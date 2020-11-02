#ifndef ADS_SET_H
#define ADS_SET_H

//https://cewebs.cs.univie.ac.at/ADS/ws20/index.php?m=D&t=unterlagen&c=show&CEWebS_what=Projekt
//https://cewebs.cs.univie.ac.at/ADS/ws20/index.php?m=D&t=info&c=show&CEWebS_what=bintree#toc

#include <functional>
#include <algorithm>
#include <iostream>
#include <stdexcept>

//Bei einem binären Suchbaum gibt es nichts zu konfigurieren, 
//der zweite Template-Parameter wird daher ignoriert. 
template <typename Key, size_t = 0>
class ADS_set {
	//Datenstruktur
	private:
		struct Node; 
		using Link = Node*;
		struct Node {
			key_type key;
			Link left;
			Link right;
			Node(const value_type& key, Link left = nullptr, Link right = nullptr) : 
					key(key), left(left), right(right) {}
			~Node() { delete left; delete right; }
		};
		Link	root{ nullptr };
		size_t	sz{ 0 };
		
		//Die korrekte Initialisierung der Instanzvariablen wid durch 
		//in-class initializer sichergestellt. Die Kopie eines Baumes wird mit 
		//der privaten Klassenmethode clone() realisiert, die rekursiv eine 1:1-Kopie erzeugt.
		static Link clone(Link link) {
			return link ? new Node(link->key, clone(link->left), clone(link->right)) : nullptr;
		}
		// die private Klassenmethode fur insert
		Link insert_key(const key_type& key) {
			Link& link{ find(key, root) };
			if (!link) {
				link = new Node(key);
				++sz;
			}
			return link;
		}
		//find liefert eine Referenz auf jenen Zeiger, der auf den gesuchten Knoten zeigt, falls dieser vorhanden ist
		static Link& find(const key_type& key, Link& link) {
			if (!link || key_equal{}(link->key, key)) return link;
			return find(key, key_compare{}(key, link->key) ? link->left : link->right);
		}

		Link find_key(const key_type& key) const {
			Link root_copy{ root };
			return find(key, root_copy);
		}
		//clear entfernt mit Hilfe des rekursiven Node-Destruktors alle Knoten aus dem Baum. 
		//erase entfernt den Knoten mit dem Wert key mit Hilfe der privaten Methode erase_key. 
		size_type erase_key(const key_type& key) {
			if (Link & link{ find(key, root) }) {
				delete unlink(link);
				--sz;
				return 1;
			}
			return 0;
		}

		/*
			unlink unterscheidet beim Entfernen eines Knotens vier Fälle(wobei Fall 1 und 2 im Code gleich behandelt werden) :
			1. Der Knoten ist ein Blatt : Er kann einfach entfernt werden.
			2. Der Knoten hat keinen linken Nachfolger : Er wird durch seinen rechten Nachfolger ersetzt.
			3. Der Knoten hat keinen rechten Nachfolger : Er wird durch seinen linken Nachfolger ersetzt.
			4. Der Knoten hat zwei Nachfolger : Er wird durch den kleinsten Knoten im rechten Teilbaum ersetzt
				(alternativ wäre der größte im linken möglich).
				Die Entfernung des kleinsten Knoten im rechten Teilbaum wird von unlink_min erledigt.
		*/

		static Link unlink(Link& link) {
			Link old_link{ link };
			if (!old_link->left) { link = old_link->right; }
			else if (!old_link->right) { link = old_link->left; }
			else {
				link = unlink_min(link->right);
				link->left = old_link->left;
				link->right = old_link->right;
			}
			old_link->left = old_link->right = nullptr;
			return old_link;
		}

		static Link unlink_min(Link& link) {
			if (link->left) return unlink_min(link->left);
			Link min_link{ link };
			link = min_link->right;
			min_link->right = nullptr;
			return min_link;
		}

	public:
		class Iterator;
		using value_type = Key;
		using key_type = Key;
		using reference = key_type &;
		using const_reference = const key_type &;
		using size_type = size_t;
		using difference_type = std::ptrdiff_t;
		using iterator = Iterator;
		using const_iterator = Iterator;
		using key_compare = std::less<key_type>;   // B+-Tree
		using key_equal = std::equal_to<key_type>; // Hashing
		using hasher = std::hash<key_type>;        // Hashing

		ADS_set() {};
		ADS_set(std::initializer_list<key_type> ilist) 
			{ insert(ilist); };
		template<typename InputIt> ADS_set(InputIt first, InputIt last) 
			{ insert(first, last); }
		ADS_set(const ADS_set &other) 
			{ root = clone(other.root); sz = other.sz; };
		~ADS_set() { delete root; root = nullptr; };

		ADS_set &operator = (const ADS_set &other) {
			if (this == &other) return *this;
			delete root;
			root = clone(other.root);
			sz = other.sz;
			return *this;
		};
		ADS_set &operator = (std::initializer_list<key_type> ilist) {
			clear();
			insert(ilist);
			return *this;
		};

		size_type	size() const  { return sz; };
		bool		empty() const { return !sz; };
		size_type	count(const key_type &key) const { return !!find_key(key); };
		iterator	find(const key_type &key) const {
			if (Link link{ find_key(key) }) return const_iterator{ root, link };
			return end();
		};
		void		clear() {
			delete root;
			root = nullptr;
			sz = 0;
		};
		size_type	erase(const key_type& key) {
			return erase_key(key);
		}
		void	swap(ADS_set &other) { lhs.swap(rhs); };
		
		//--- Einfuegen
		void	insert(std::initializer_list<key_type> ilist) {
			for (const key_type& key : ilist) insert_key(key);
		};
		std::pair<iterator,bool>			insert(const key_type &key) {
			size_type sz_before{ sz };
			Link link{ insert_key(key) };
			return std::make_pair(const_iterator{ root, link }, sz != sz_before);
		};
		template<typename InputIt> void		insert(InputIt first, InputIt last) {
			while (first != last) insert_key(*first++);
		};
		size_type		erase(const key_type &key);

		const_iterator	begin() const { return const_iterator{ root }; }
		const_iterator	end() const { return const_iterator{}; }

		void			dump(std::ostream& o = std::cerr) const { dump(root, o);}
		static void		dump(Link link, std::ostream& o, size_t ind = 0) {
			if (!link) return;
			dump(link->right, o, ind + 1);
			o << std::setw(ind * 4) << "" << link->key << '\n';
			dump(link->left, o, ind + 1);
		}

		friend bool operator==(const ADS_set& lhs, const ADS_set& rhs) {
			if (lhs.size() != rhs.size()) return false;
			auto lhs_it{ lhs.begin() };
			auto rhs_it{ rhs.begin() };
			for (; lhs_it != lhs.end(); ++lhs_it, ++rhs_it) if (!key_equal{}(*lhs_it, *rhs_it)) return false;
			return true;
		}
		friend bool operator!=(const ADS_set& lhs, const ADS_set& rhs) { return !(lhs == rhs); }

};

template <typename Key, size_t N>
class ADS_set<Key,N>::Iterator {
	private:
		std::stack<Link> path;
	public:
		using value_type = Key;
		using difference_type = std::ptrdiff_t;
		using reference = const value_type &;
		using pointer = const value_type *;
		using iterator_category = std::forward_iterator_tag;


		explicit Iterator(Link root = nullptr, Link current = nullptr) {
			if (!root) return; // end
			if (!current) {    // begin
				path.push(root);
				while (path.top()->left) path.push(path.top()->left);
				return;
			}
			Link link{ root };
			while (link != current) {
				if (key_compare{}(current->key, link->key)) {
					path.push(link);
					link = link->left;
				}
				else {
					link = link->right;
				}
			}
			path.push(link);
		}


		reference	operator*() const { return path.top()->key; }
		pointer		operator->() const { return &path.top()->key; }
		Iterator&	operator++() {
			Link old_top{ path.top() };
			path.pop();
			if (old_top->right) {
				path.push(old_top->right);
				while (path.top()->left) path.push(path.top()->left);
			}
			return *this;
		}
		Iterator	operator++(int) { Iterator tmp{ *this }; ++* this; return tmp; }


		friend bool operator == (const Iterator& lhs, const Iterator& rhs) {
			return lhs.path.size() == rhs.path.size() && (lhs.path.empty() || lhs.path.top() == rhs.path.top());
		}
		friend bool operator != (const Iterator& lhs, const Iterator& rhs) { return !(lhs == rhs); }

};

template <typename Key, size_t N> void swap(ADS_set<Key,N> &lhs, ADS_set<Key,N> &rhs) { lhs.swap(rhs); }

#endif // ADS_SET_H
