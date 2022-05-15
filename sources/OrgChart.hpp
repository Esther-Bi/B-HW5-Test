#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#ifndef MY_HEADER
#define MY_HEADER

namespace ariel{

    static const int LEVEL_ORDER = 0 ;
    static const int REVERSE_LEVEL_ORDER = 1 ;
    static const int PRE_ORDER = 2 ;

    class OrgChart{

        struct Node{
            std::string data;
            std::vector<Node*>childs;

            Node(const std::string &data) {
                this->data = data;
            }
            ~Node(){}
        };

		class iterator_level{
            private:
                Node *curr;

			public:
                std::vector<std::string> ordered;
                iterator_level(Node* start,const int& order){
                    ordered.push_back("asd");
                    ordered.push_back("qwe");
                    ordered.push_back("zxc");
                }

                bool operator==(const iterator_level&it)const{
                        return true;
                }
                bool operator!=(const iterator_level&it)const{
                        return true;
                }

                iterator_level &operator++() {
                    if (!ordered.empty()) {
                        ordered.erase(ordered.begin());
                    }
                    return *this;
                }

                iterator_level operator++(int) {
                    iterator_level t = *this;
                    ++*this;
                    return t;
                }
                ~iterator_level(){}
		};

        class iterator_reverse{
            private:
                Node *curr;

			public:
                std::vector<std::string> ordered;
                iterator_reverse(Node* start,const int& order){
                    ordered.push_back("asd");
                    ordered.push_back("qwe");
                    ordered.push_back("zxc");
                }
    

                bool operator==(const iterator_reverse&it)const{
                        return true;
                }
                bool operator!=(const iterator_reverse&it)const{
                        return true;
                    }

                iterator_reverse &operator++() {
                    if (!ordered.empty()) {
                        ordered.erase(ordered.begin());
                    }
                    return *this;
                }

                iterator_reverse operator++(int) {
                    iterator_reverse t = *this;
                    ++*this;
                    return t;
                }
                ~iterator_reverse(){}
		};

        class iterator_pre{
            private:
                Node *curr;

			public:
                std::vector<std::string> ordered;
                iterator_pre(Node* start,const int& order){
                    ordered.push_back("asd");
                    ordered.push_back("qwe");
                    ordered.push_back("zxc");
                }
    

                bool operator==(const iterator_pre&it)const{
                    return true;
                }

                bool operator!=(const iterator_pre&it)const{
                        return true;
                }
        
                iterator_pre &operator++() {
                    if (!ordered.empty()) {
                        ordered.erase(ordered.begin());
                    }
                    return *this;
                }

                iterator_pre operator++(int) {
                    iterator_pre t = *this;
                    ++*this;
                    return t;
                }
                ~iterator_pre(){}
		};











        std::string s = "esther";
        private:
            Node *root;

        public:
            OrgChart();
            OrgChart& add_root(const std::string &father);
            OrgChart& add_sub(const std::string &father,const std::string &son);
            friend std::ostream &operator<<(std::ostream &os,  OrgChart &org);

			std::string* begin_level_order();
			std::string* end_level_order();
			std::string* begin_reverse_order();
			std::string* reverse_order();
            std::string* begin_preorder();
            std::string* end_preorder();
			std::string* begin();
			std::string* end();
            ~OrgChart();

    };
}

#endif