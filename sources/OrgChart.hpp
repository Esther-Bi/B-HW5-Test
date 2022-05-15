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
                    // this->curr = start;
                    
                    // if(order == LEVEL_ORDER){
                    //     this->ordered.clear();
                    //     if (start != nullptr) {
                    //         this->ordered.push_back(start->data);
                    //     }
                    //     fill_level_order(start);
                    // }
                    // else if(order == REVERSE_LEVEL_ORDER){
                    //     this->ordered.clear();
                    //     if (start != nullptr) {
                    //         this->ordered.insert(this->ordered.begin(), start->data);
                    //     }
                    //     fill_rev_order(start);
                    //     // curr = this->ordered.at((unsigned long)0);
                    // }
                    // else if(order == PRE_ORDER){
                    //     this->ordered.clear();
                    //     if (start != nullptr) {
                    //         this->ordered.push_back(start->data);
                    //     }
                    //     fill_preorder(start);
                    // }
                    // this->ordered.push_back(nullptr);
                }

                // void fill_level_order(Node *head){
                //     if(head!=nullptr){
                //         for(size_t i=0 ; i<head->childs.size() ; i++){
                //             this->ordered.push_back(head->childs[i]->data);
                //         }
                //         for(size_t i=0 ; i<head->childs.size() ; i++){
                //             fill_level_order(head->childs[i]);
                //         }
                //     }
                // }

                // void fill_rev_order(Node *head){
                //     if(head!=nullptr){
                //         for(size_t i=head->childs.size();i>0;i--){
                //             this->ordered.insert(this->ordered.begin(), head->childs[i-1]->data);
                //         }
                //         for(size_t i=head->childs.size();i>0;i--){
                //             fill_rev_order(head->childs[i-1]);
                //         } 
                //     }
                // }

                // void fill_preorder(Node *head){
                //     if(head!=nullptr){
                //         for(size_t i=0;i<head->childs.size();i++){
                //             this->ordered.push_back(head->childs[i]->data);
                //             fill_preorder(head->childs[i]);
                //         }
                //     }
                // }

                bool operator==(const iterator_level&it)const{
                    // if (curr == nullptr || it.curr == nullptr) {
                    //         return it.curr == curr;
                    // }
                        return true;
                    }
                bool operator!=(const iterator_level&it)const{
                        return true;
                    }
                std::string& operator*()const{
                        return curr->data;
                    }

                std::string* operator->() const {
                        return &(curr->data);
                    }
                iterator_level &operator++() {
                    if (!ordered.empty()) {
                        ordered.erase(ordered.begin());
                        // curr = this->ordered.at((unsigned long)0);
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
                    // if (curr == nullptr || it.curr == nullptr) {
                    //         return it.curr == curr;
                    // }
                        return true;
                    }
                bool operator!=(const iterator_reverse&it)const{
                        return true;
                    }
                std::string& operator*()const{
                        return curr->data;
                    }

                std::string* operator->() const {
                        return &(curr->data);
                    }
                iterator_reverse &operator++() {
                    if (!ordered.empty()) {
                        ordered.erase(ordered.begin());
                        // curr = this->ordered.at((unsigned long)0);
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
                    // if (curr == nullptr || it.curr == nullptr) {
                    //         return it.curr == curr;
                    // }
                        return true;
                    }
                bool operator!=(const iterator_pre&it)const{
                        return true;
                    }
                std::string& operator*()const{
                        return curr->data;
                    }

                std::string* operator->() const {
                        return &(curr->data);
                    }
                iterator_pre &operator++() {
                    if (!ordered.empty()) {
                        ordered.erase(ordered.begin());
                        // curr = this->ordered.at((unsigned long)0);
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
        int x = 8;
        private:
            Node *root;

        public:
            OrgChart();
            OrgChart& add_root(const std::string &job);
            OrgChart& add_sub(const std::string &bos,const std::string &sub);
            // Node* find_node(const std::string &name);
            friend std::ostream &operator<<(std::ostream &os,  OrgChart &org);

			std::string* begin_level_order();
			std::string* end_level_order();
			std::string* begin_reverse_order();
			std::string* reverse_order();
            std::string* begin_preorder();
            std::string* end_preorder();
			int* begin();
			int* end();
            ~OrgChart();

    };
}

#endif