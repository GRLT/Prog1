#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main() {
  try {
    Point x{100, 100};
    Simple_window win{x, 800, 1000, "Canvas"};

    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;

    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid) {
      cout << x_grid;
      grid.add(Point{x, 0}, Point{x, y_size});
    }
    for (int y = y_grid; y < y_size; y += y_grid) {
      grid.add(Point{0, y}, Point{x_size, y});
    }
    win.attach(grid);

    Vector_ref<Rectangle> rect;
    for (int i = 0; i < x_size; i++) {
      rect.push_back(
          new Graph_lib::Rectangle(Point(i * 100, i * 100), 101, 101));
      rect[rect.size() - 1].set_fill_color(Color::red);
      win.attach(rect[rect.size() - 1]);
    }

    Image img1{Point{0, 300}, "owl.jpg"};
    Image img2{Point{300, 600}, "owl.jpg"};
    Image img3{Point{500, 100}, "owl.jpg"};
    win.attach(img1);
    win.attach(img2);
    win.attach(img3);
    win.wait_for_button();

    Image img0{Point{0, 0}, "rnd.jpg"};
    win.attach(img0);
    win.wait_for_button();

    for (int j = 0; j < 8; ++j) {
      if (win.wait_for_button() && img0.point(0).x != win.x_max()) {
        img0.move(100, 0);
      } else if (win.wait_for_button() && img0.point(0).x != -win.x_max()) {
        img0.move(-100, 0);
      } else if (win.wait_for_button() && img0.point(0).y != win.y_max()) {
        img0.move(0, 100);
      } else if (win.wait_for_button() && img0.point(0).y != -win.y_max()) {
        img0.move(0, -100);
      }
    }

    win.wait_for_button();

  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}