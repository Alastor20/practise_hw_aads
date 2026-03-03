#include <cstddef>
#include <iterator>

template < class T > T *merge(const T *const *a, size_t sa, const size_t *sai, T *c)
{
  size_t size = std::size(c);
  size_t *szs = new size_t[sa];
  for (size_t i = 0; i < size; ++i) {
    size_t idx = 0;
    T &min = a[0][szs[0]];
    for (size_t j = 0; j < sa; ++j) {
      if (szs[j] < sai[j]) {
        if (min > a[j][szs[j]]) {
          min = a[j][szs[j]];
          idx = j;
        }
      }
    }
    c[i] = min;
    ++szs[idx];
  }
  delete[] szs;
  return c;
}

int main()
{}
