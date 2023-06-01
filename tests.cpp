/// @filename tests.cpp
/// @date March 7, 2023

/// Provided testing file to implement
/// framework based tests in. The example
/// below uses the Catch testing framework
/// version that uses a single .hpp file.

// This tells Catch to provide a main()
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "shape.h"
#include "canvaslist.h"

using namespace std;

TEST_CASE("(0) no tests") 
{
  //
  // done
  //
}

TEST_CASE("getX Shape test")
{
  Shape* test = new Shape(3, 4);
  REQUIRE(test->getX() == 3);
}

TEST_CASE("getY Shape test") 
{
  Shape* test = new Shape(3,4);
  REQUIRE(test->getY() == 4);
}

TEST_CASE("setX Shape test") 
{
  Shape* test = new Shape();
  test->setX(3);
  REQUIRE(test->getX() == 3);
}

TEST_CASE("setY Shape test") 
{
  Shape* test = new Shape();
  test->setY(4);
  REQUIRE(test->getY() == 4);
}

TEST_CASE("getRadius Circle test") {
  Circle* test = new Circle(5);
  REQUIRE(test->getRadius() == 5);
}

TEST_CASE("setRadius Circle test") 
{
  Circle* test = new Circle();
  test->setRadius(5);
  REQUIRE(test->getRadius() == 5);
}

TEST_CASE("getWidth Rectangle test") 
{
  class Rectangle* test = new class Rectangle(4, 3);
  REQUIRE(test->getWidth() == 4);
}

TEST_CASE("getHeight Rectangle test") 
{
  class Rectangle* test = new class Rectangle(4,3);
  REQUIRE(test->getHeight() == 3);
}

TEST_CASE("setWidth Rectangle test") 
{
  class Rectangle* test = new class Rectangle(4,3);
  test->setWidth(5);
  REQUIRE(test->getWidth() == 5);
}

TEST_CASE("setHeight Rectangle test")
{
  class Rectangle* test = new class Rectangle(4,3);
  test->setHeight(5);
  REQUIRE(test->getHeight() == 5);
}

TEST_CASE("getBase RightTriangle test")
{
  RightTriangle* test = new RightTriangle(4,5);
  REQUIRE(test->getBase() == 4);
}

TEST_CASE("getHeight RightTriangle test")
{
  RightTriangle* test = new RightTriangle(4,5);
  REQUIRE(test->getHeight() == 5);
}

TEST_CASE("setBase RightTriangle test") 
{
  RightTriangle* test = new RightTriangle(4,5);
  test->setBase(3);
  REQUIRE(test->getBase() == 3);
}

TEST_CASE("setHeight RightTriangle test") 
{
  RightTriangle* test = new RightTriangle(4,5);
  test->setHeight(3);
  REQUIRE(test->getHeight() == 3);
}

TEST_CASE("insertAfter CanvasList test")
{
  RightTriangle* test = new RightTriangle(4,5);
  CanvasList* list = new CanvasList();
  list->insertAfter(0, test);
  REQUIRE(list->shapeAt(0) == test);
}

TEST_CASE("clear CanvasList test")
{
  RightTriangle* test = new RightTriangle(4,5);
  CanvasList* list = new CanvasList();
  list->insertAfter(0, test);
  list->clear();
  REQUIRE(list->isempty() == true);
}

TEST_CASE("push_front CanvasList test") 
{
  RightTriangle* test = new RightTriangle(4,5);
  CanvasList* list = new CanvasList();
  list->push_front(test);
  REQUIRE(list->shapeAt(0) == test);
}

TEST_CASE("push_back CanvasList test") 
{
  RightTriangle* test = new RightTriangle(4,5);
  CanvasList* list = new CanvasList();
  list->push_back(test);
  REQUIRE(list->shapeAt(0) == test);
}

TEST_CASE("removeAt CanvasList test")
{
  RightTriangle* test = new RightTriangle(4,5);
  CanvasList* list = new CanvasList();
  list->insertAfter(0, test);
  list->removeAt(0);
  REQUIRE(list->isempty() == true);
}

TEST_CASE("pop_front CanvasList test")
{
  RightTriangle* test = new RightTriangle(4,5);
  CanvasList* list = new CanvasList();
  list->insertAfter(0, test);
  list->pop_front();
  REQUIRE(list->isempty() == true);
}

TEST_CASE("pop_back CanvasList test")
{
  RightTriangle* test = new RightTriangle(4,5);
  CanvasList* list = new CanvasList();
  list->insertAfter(0, test);
  list->pop_back();
  REQUIRE(list->isempty() == true);
}

TEST_CASE("size CanvasList test")
{
  RightTriangle* test = new RightTriangle(4,5);
  CanvasList* list = new CanvasList();
  list->insertAfter(0, test);
  REQUIRE(list->size() == 1);
}

TEST_CASE("find CanvasList test")
{
  RightTriangle* test = new RightTriangle(4,5);
  CanvasList* list = new CanvasList();
  list->insertAfter(0, test);
  int search = list->find(4,5);
  REQUIRE(search == 1);
}

TEST_CASE("shapeAt CanvasList test")
{
  RightTriangle* test = new RightTriangle(4,5);
  CanvasList* list = new CanvasList();
  list->insertAfter(0, test);
  Shape* temp = list->shapeAt(0);
  REQUIRE(temp == test);
}