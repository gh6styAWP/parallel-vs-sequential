# parallel-vs-sequential

## Задание

1. Сгенерировать массив случайных целых чисел:
   - размер массива — не менее 100 000 элементов;
   - значения элементов — в диапазоне от 0 до 100 включительно.

2. Реализовать поиск повторяющихся значений:
   - для выбранного индекса `i` найти все элементы массива,
     значения которых равны значению `array[i]`
     (то есть определить все повторения значения по выбранному индексу).

3. Сравнить производительность двух вариантов реализации:
   - последовательная (без распараллеливания);
   - параллельная (с использованием многопоточности / распараллеливания).

4. По результатам вывести время выполнения для каждого варианта и сделать краткий вывод.

## Task

1. Generate an array of random integers:
  - array size — at least 100,000 elements;
  - element values — in the range from 0 to 100 inclusive.

2. Implement search for duplicate values:
  - for a chosen index i, find all elements of the array whose values are equal to array[i]
  (i.e., determine all occurrences of the value at the selected index).

3. Compare the performance of two implementation variants:
  - sequential (without parallelization);
  - parallel (using multithreading / parallelization).

4. Based on the results, output the execution time for each variant and make a brief conclusion.
