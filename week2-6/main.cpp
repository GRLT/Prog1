/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Graph.h"
#include "Simple_window.h"

int main() {
  try {
    Point tl{100, 100};
    Simple_window win{tl, 600, 400, "Canvas"};

    Axis xa{Axis::x, Point{20,300}, 280, 10, "x axis"};
    win.attach(xa);
    win.set_label("Canvas#2");

    Axis ya{Axis::y, Point{20,300}, 280, 10, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("Canvas #3");



    Function sine {sin,0,100,Point{20,150},1000,50,50};
    win.attach(sine);
    sine.set_color(Color::blue);

    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,700});

    poly.set_color(Color::red);
    poly.set_style(Line_style::dashdot);
    win.attach(poly);
    win.set_label("Canvas 5");

    Rectangle r {Point{200,200},100,80};
    win.attach(r);
    win.set_label("Canvas 6");

    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{400,100});
    poly_rect.add(Point{100,100});
    win.attach(poly_rect);
    poly_rect.add(Point{50,75});

    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dot,4));
    poly_rect.set_style(Line_style(Line_style::solid,2));
    poly_rect.set_fill_color(Color::dark_red);
    win.set_label("Canvas #7");

    Text t {Point{150,200}, "Hello World of Graphics!"};
    win.attach(t);
    win.set_label("Canvas #8");
    t.set_font(Font::times);
    t.set_font_size(50);
    win.set_label("Canvas #9");
/*
    Image ii {Point{100,50},"duck.jpg"}; // Doesn't support .png
    win.attach(ii);
    win.set_label("Canvas #10");
*/  
    Circle c {Point{100,200}, 60};
    c.set_color(Color::red);
    Mark m {Point{230,200},'x'};

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes {Point{100,80},oss.str()};

    win.attach(c);
    win.attach(m);
    win.attach(sizes);
    win.set_label("Canvas #12");


    win.wait_for_button();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  using namespace Graph_lib;
}