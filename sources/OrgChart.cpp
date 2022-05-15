#include "OrgChart.hpp"
using namespace std;

namespace ariel
{

    OrgChart::OrgChart(){
        // constuctor
    }
    OrgChart& OrgChart::add_root(const std::string &father){
        return *this;
    }
    OrgChart& OrgChart::add_sub(const std::string &father,const std::string &son){
        return *this;
    }

    std::ostream &operator<<(std::ostream &os,  OrgChart &org){
        os << "1234";
        return os;
    }

    string* OrgChart::begin_level_order(){
        iterator_level ans = iterator_level{root,LEVEL_ORDER};
        // return &(ans.ordered.at((unsigned long) 0));
        return &s;
    }
    string* OrgChart::end_level_order(){
        iterator_level ans = iterator_level{nullptr,3};
        // return &(ans.ordered.at((unsigned long) (ans.ordered.size()-1))); 
        return &s;
    }
    string* OrgChart::begin_reverse_order(){
        iterator_reverse ans = iterator_reverse{root,REVERSE_LEVEL_ORDER};
        // return &(ans.ordered.at((unsigned long) 0));
        return &s;
    }
    string* OrgChart::reverse_order(){
        iterator_reverse ans = iterator_reverse{nullptr,3};
        // return &(ans.ordered.at((unsigned long) (ans.ordered.size()-1))); 
        return &s;
    }
    string* OrgChart::begin_preorder(){
        iterator_pre ans = iterator_pre{root,PRE_ORDER};
        // return &(ans.ordered.at((unsigned long) 0));
        return &s;
    }
    string* OrgChart::end_preorder(){
        iterator_pre ans = iterator_pre{nullptr,3};
        // return &(ans.ordered.at((unsigned long) (ans.ordered.size()-1))); 
        return &s;
    }
    int* OrgChart::begin(){
        // return begin_level_order();
        return &x;
    }
    int* OrgChart::end(){
        // return end_level_order();
        return &x;
    }
    OrgChart::~OrgChart(){
    }

}




