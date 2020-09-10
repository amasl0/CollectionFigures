# CollectionFigures
Выполненное задание по наследованию из курса "Основы разработки на С++: Жёлтый пояс". 

Задание:
Вам дана функция main, которая считывает из стандартного ввода команды по работе с набором геометрических фигур:
int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}

Как видно из кода, есть два вида команд:

ADD — добавить фигуру в набор;
PRINT — для каждой фигуры в наборе распечатать название, периметр и площадь.
Программа поддерживает три вида фигур: прямоугольник, треугольник и круг. Их добавление описывается так:

ADD RECT width height — добавить прямоугольник с размерами width и height (например, ADD RECT 2 3).
ADD TRIANGLE a b c — добавить треугольник со сторонами a, b и c (например, ADD TRIANGLE 3 4 5).
ADD CIRCLE r — добавить круг радиуса r (например, ADD CIRCLE 5).
