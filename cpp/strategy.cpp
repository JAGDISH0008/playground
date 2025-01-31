#include <iostream>
class Strategy
{
public:
  virtual ~Strategy() {}
  virtual void algorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
  ~ConcreteStrategyA() {}

  void algorithmInterface()
  {
    std::cout << "Concrete Strategy A" << std::endl;
  }
};

class ConcreteStrategyB : public Strategy
{
public:
  ~ConcreteStrategyB() {}

  void algorithmInterface()
  {
    std::cout << "Concrete Strategy B" << std::endl;
  }
};

class ConcreteStrategyC : public Strategy
{
public:
  ~ConcreteStrategyC() {}

  void algorithmInterface()
  {
    std::cout << "Concrete Strategy C" << std::endl;
  }
};

class Context
{
public:
  Context(Strategy *const s) : strategy(s) {}

  ~Context()
  {
    delete strategy;
  }

  void contextInterface()
  {
    strategy->algorithmInterface();
  }

private:
  Strategy *strategy;
};

int main()
{
  Context context(new ConcreteStrategyA());
  context.contextInterface();

  return 0;
}