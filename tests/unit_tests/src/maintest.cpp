#include "maintest.h"
#include "impl.h"

#include "impl.h"
#include <gtest/gtest.h>

using namespace Lab10;

TEST(Lab10,SortList)
{
    LinkedList<int> myList{3,2,1};

    myList.sort([](int x,int y) { return x < y;});

    LinkedList<int> expectedList{1,2,3};

    ASSERT_EQ(myList,expectedList);

}
