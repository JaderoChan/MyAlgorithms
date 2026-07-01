#include <cstdint>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include <sorts.h>

class ElapsedTimer
{
public:
    ElapsedTimer() : start_(clock()) {}

    void     restart()
    { start_ = clock(); }

    double   elapsedSec() const
    { return static_cast<double>(clock() - start_) / static_cast<double>(CLOCKS_PER_SEC); }
    uint64_t elapsedMs() const
    { return static_cast<uint64_t>(elapsedSec() * 1000.0); }

    double   elapsedSecRestart()
    { const double sec  = elapsedSec(); restart(); return sec; }
    uint64_t elapsedMsRestart()
    { const uint64_t ms = elapsedMs();  restart(); return ms;}

private:
    clock_t start_;
};

static std::vector<int> generateRandomNums(size_t count, int min, int max)
{
    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::uniform_int_distribution<int> uni(min, max);

    std::vector<int> nums;
    nums.reserve(count);
    while (count--)
        nums.push_back(uni(mt));

    return nums;
}

template <typename T>
static std::ostream& operator<<(std::ostream& os, const std::vector<T>& arr)
{
    constexpr size_t cols = 16;
    size_t rows = static_cast<size_t>(static_cast<double>(arr.size()) / static_cast<double>(cols));
    for (size_t row = 0; row < rows; ++row)
    {
        os << "[";
        for (size_t col = 0; col < cols; ++col)
        {
            const size_t idx = row * cols + col;
            if (idx >= arr.size())
                break;
            os << arr[idx] << (col != cols - 1 ? ",\t" : "");
        }
        os << "]" << (row != rows - 1 ? "\n" : "");
    }
    return os;
}

JCALGO_DEFINE_BUBBLE_SORT(int, JCALGO_DEFAULT_LESS_THAN)
JCALGO_DEFINE_SELECT_SORT(int, JCALGO_DEFAULT_LESS_THAN)
JCALGO_DEFINE_QUICK_SORT(int, JCALGO_DEFAULT_LESS_THAN)

int main(int argc, char* argv[])
{
    constexpr size_t n = 1000000;
    const std::vector<int> originNums = generateRandomNums(n, -10000, 10000);
    // std::cout << "------------------------------\n";
    // std::cout << "Origin Nums:\n------------------------------\n" << originNums << std::endl;

    ElapsedTimer et;

    // Bubble sort
    {
        std::vector<int> nums = originNums;
        et.restart();
        jcalgo_bubble_sort_int(nums.data(), n);
        double elapsed = et.elapsedSec();
        // std::cout << "------------------------------\n";
        // std::cout << "Bubble sorted nums:\n------------------------------\n" << nums << std::endl;
        std::cout << "[Bubble sort elapsed: " << elapsed << "]" << std::endl;
    }

    // Select sort
    {
        std::vector<int> nums = originNums;
        et.restart();
        jcalgo_select_sort_int(nums.data(), n);
        double elapsed = et.elapsedSec();
        // std::cout << "------------------------------\n";
        // std::cout << "Select sorted nums:\n------------------------------\n" << nums << std::endl;
        std::cout << "[Select sort elapsed: " << elapsed << "]" << std::endl;
    }

    // Quick sort
    {
        std::vector<int> nums = originNums;
        et.restart();
        jcalgo_quick_sort_int(nums.data(), n);
        double elapsed = et.elapsedSec();
        // std::cout << "------------------------------\n";
        // std::cout << "Quick sorted nums:\n------------------------------\n" << nums << std::endl;
        std::cout << "[Quick sort elapsed: " << elapsed << "]" << std::endl;
    }

    return 0;
}
