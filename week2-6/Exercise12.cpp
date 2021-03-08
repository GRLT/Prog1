/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main
   `fltk-config --ldflags --use-images`
*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main() {
  try {
    Simple_window win{Point{100, 100}, 600, 400, "Canvas"};

    //Exercise 1/A
    Rectangle r(Point{300, 300}, 100, 80);
    r.set_color(Color::blue);
   // win.attach(r);

    //Exercise 1/B
    Polygon p;
    p.add(Point{200, 200}); //FB
    p.add(Point{200, 300}); //LB
    p.add(Point{350, 300}); //LJ
    p.add(Point{350, 200}); //FJ
    p.set_color(Color::red);
   // win.attach(p);

    Rectangle k{Point{100,200}, 100, 30};
    Text t{Point{130,220}, "Howdy!"};
    win.attach(t);
    win.attach(k);

    Closed_polyline letter_b;
    letter_b.add(Point(100,100));
    letter_b.add(Point(150,100));
    letter_b.add(Point(170,125));
    letter_b.add(Point(170,150));
    letter_b.add(Point(150,175));
    letter_b.add(Point(100,175));
    letter_b.add(Point(150,175));
    letter_b.add(Point(175,200));
    letter_b.add(Point(175,225));
    letter_b.add(Point(150,250));
    letter_b.add(Point(100,250));
    letter_b.set_color(Color::blue);
    letter_b.set_style(Line_style(Line_style::solid,4));
    win.attach(letter_b);

    Open_polyline letter_w;
    letter_w.add(Point(190,100));
    letter_w.add(Point(215,250));
    letter_w.add(Point(240,175));
    letter_w.add(Point(265,250));
    letter_w.add(Point(290,100));
    letter_w.set_color(Color::red);
    letter_w.set_style(Line_style(Line_style::solid,4));
    win.attach(letter_w);


    win.wait_for_button();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}