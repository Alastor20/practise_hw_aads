#include <cstddef>

size_t valid_index(size_t sa, const size_t *sai, const size_t *sizes)
{
  for (size_t j = 0; j < sa; ++j) {
    if (sizes[j] < sai[j]) {
      return j;
    }
  }
  return sa;
}

template < class T > T *merge(const T *const *a, size_t sa, const size_t *sai, T *c)
{
  size_t *sizes = new size_t[sa]();
  size_t minId = valid_index(sa, sai, sizes), i = 0;
  while (minId != sa) {
    for (size_t j = 0; j < sa; ++j) {
      if (sizes[j] < sai[j]) {
        if (a[minId][sizes[minId]] > a[j][sizes[j]]) { // T::operator<
          minId = j;
        }
      }
    }
    c[i++] = a[minId][sizes[minId]]; // T::T(const T&)
    ++sizes[minId];
    minId = valid_index(sa, sai, sizes);
  }
  delete[] sizes;
  return c;
}

// Неявный интерфейс: T::operator<, T::T(const T&)
// Недостатки явного интерфейса: пользователю самому придётся выделять память под функцию
