#include <memory>

template <typename T>
class Rules
{
  public:
    Rules()
        : resource_(nullptr) { }
    ~Rules()
    {
        delete resource_;
    }

    Rules(T* resourcePtr)
        : resource_(resourcePtr)
    {
    }

    Rules(const Rules& other)
        : resource_(new T { *other.resource_ }) { }

    Rules& operator=(const Rules& other)
    {
        delete resource_;
        resource_ = new T { *other.resource_ };

        return *this;
    }

    Rules(Rules&& other)
        : resource_(other.resource_)
    {
        other.resource_ = nullptr;
    }
    Rules& operator=(Rules&& other)
    {
        delete resource_;
        resource_ = other.resource_;
        other.resource_ = nullptr;

        return *this;
    }

  private:
    T* resource_;
};

int main(int argc, const char** argv)
{
    Rules<int> r(new int { 42 });
    auto r2 = r;
    r = r2;
    auto r3 = std::move(r);
    r = std::move(r3);

    return 0;
}