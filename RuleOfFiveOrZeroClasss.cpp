#include <memory>

template <typename T>
class Rules
{
  public:
    Rules(T* resourcePtr)
        : resource_(resourcePtr)
    {
    }

  private:
    std::unique_ptr<T> resource_;
};

int main(int argc, const char** argv)
{
    Rules<int> r(new int { 42 });
    // auto r2 = r; // copying deleted
    // r = r2;
    auto r3 = std::move(r);
    r = std::move(r3);

    return 0;
}