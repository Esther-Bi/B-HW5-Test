#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
#include "OrgChart.hpp"

TEST_CASE("Good level order") {
	/***
	check level order
	***/
    ariel::OrgChart organization;
    organization.add_root("a")
        .add_sub("a", "b1")
        .add_sub("a", "b2")
        .add_sub("a", "b3")
        .add_sub("b1", "c11")
        .add_sub("b3", "c31");
    std::string order = "";
    std::string correct = "a b1 b2 b3 c11 c31 ";
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
        order += (*it);
        order += " ";
    }
    CHECK_EQ(order , correct);
    organization.add_sub("c31" , "d");
    order += "d ";
    correct += "d ";
    CHECK_EQ(order , correct);
}

TEST_CASE("Good reverse level order") {
	/***
	check reverse level order
	***/
    ariel::OrgChart organization;
    organization.add_root("a")
        .add_sub("a", "b1")
        .add_sub("a", "b2")
        .add_sub("a", "b3")
        .add_sub("b1", "c11")
        .add_sub("b3", "c31");
    std::string order = "";
    std::string correct = "c31 c11 b3 b2 b1 a ";
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it){
        order += (*it);
        order += " ";
    }
    CHECK_EQ(order , correct);
    organization.add_sub("c31" , "d");
    order = "d " + order;
    correct = "d " + correct;
    CHECK_EQ(order , correct);
}

TEST_CASE("Good pre order") {
	/***
	check pre order
	***/
    ariel::OrgChart organization;
    organization.add_root("a")
      .add_sub("a", "b1")
      .add_sub("a", "b2")
      .add_sub("a", "b3")
      .add_sub("b1", "c11")
      .add_sub("b3", "c31");
    std::string order = "";
    std::string correct = "a b1 c11 b2 b3 c31";
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it){
        order += (*it);
        order += " ";
    }
    CHECK_EQ(order , correct);
    organization.add_sub("c31" , "d");
    order += "d ";
    correct += "d ";
    CHECK_EQ(order , correct);
}

TEST_CASE("for each") {
	/***
	matrices are not the same size for comparison operators
	***/
    ariel::OrgChart organization;
    organization.add_root("a")
        .add_sub("a", "b1")
        .add_sub("a", "b2")
        .add_sub("a", "b3")
        .add_sub("b1", "c11")
        .add_sub("b3", "c31");
    std::string order = "";
    std::string correct = "a b1 b2 b3 c11 c31 ";
    for (std::string element : organization){
        order += element;
        order += " ";
    }
    CHECK_EQ(order , correct);
    organization.add_sub("c31" , "d");
    order += "d ";
    correct += "d ";
    CHECK_EQ(order , correct);
}

TEST_CASE("Bad input") {

    ariel::OrgChart organization;
    CHECK_NOTHROW(organization.add_root("a"));
    CHECK_THROWS(organization.add_sub("b", "c"));
    CHECK_THROWS(organization.add_sub("c", "d"));
    CHECK_THROWS(organization.add_sub("d", "e"));
    CHECK_THROWS(organization.add_sub("e", "f"));

}

TEST_CASE("Good inserting") {

    ariel::OrgChart organization;
    CHECK_NOTHROW(organization.add_root("a"));
    CHECK_NOTHROW(organization.add_sub("b", "a"));
    CHECK_NOTHROW(organization.add_sub("a", "d"));
    CHECK_NOTHROW(organization.add_sub("d", "a"));
    CHECK_NOTHROW(organization.add_sub("c", "d"));

}

TEST_CASE("Change root") {
    ariel::OrgChart organization;
    organization.add_root("a")
      .add_sub("a", "b")         
      .add_sub("a", "c")       
      .add_sub("a", "d")
      .add_sub("a", "e");  

    std::string order = "";
    std::string correct = "a b c d e ";
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
        order += (*it);
        order += " ";
    }
    CHECK_EQ(order , correct);        

    organization.add_root("g"); // change root
    order = "";
    correct = "g b c d e ";
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
        order += (*it);
        order += " ";
    }
    CHECK_EQ(order , correct); 

    organization.add_root("h"); // change root
    order = "";
    correct = "h b c d e ";
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
        order += (*it);
        order += " ";
    }
    CHECK_EQ(order , correct); 
}

