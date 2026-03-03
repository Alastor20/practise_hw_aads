#include <cstddef>
#include <iterator>

template < class T > T *merge(const T *const *a, size_t sa, const size_t *sai, T *c)
{
  size_t totalSize = std::size(c);
  size_t *sizes = new size_t[sa];
  for (size_t i = 0; i < totalSize; ++i) {
    size_t index = 0;
    for (size_t j = 0; j < sa; ++j) {
      if (sizes[j] < sai[j]) {
        if (a[index][sizes[index]] > a[j][sizes[j]]) { // T::operator<
          index = j;
        }
      }
    }
    c[i] = a[index][sizes[index]]; // T::T(const T&)
    ++sizes[index];
  }
  delete[] sizes;
  return c;
}

// Неявный интерфейс: T::operator<, T::T(const T&)
// Недостатки явного интерфейса: пользователю самому придётся выделять память под функцию
