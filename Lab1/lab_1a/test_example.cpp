#include <gtest/gtest.h>
#include "BitArray_realization.h" // Подключаем файл с реализацией BitArray

// Тест для конструктора по умолчанию
TEST(BitArrayTest, DefaultConstructor) {
    BitArray arr;
    EXPECT_EQ(arr.size(), 0);  // Проверяем, что размер по умолчанию равен 0
    EXPECT_TRUE(arr.empty());  // Проверяем, что массив пустой
}

// Тест для конструктора с параметрами
TEST(BitArrayTest, ParameterizedConstructor) {
    BitArray arr(8, 0b11001100); // Создаем массив с размером 8 и значением 11001100
    EXPECT_EQ(arr.size(), 8);
    EXPECT_TRUE(arr[2]); // Проверяем, что третий бит установлен
    EXPECT_FALSE(arr[0]); // Проверяем, что первый бит не установлен
}

// Тест на копирование и присваивание
TEST(BitArrayTest, CopyAndAssignment) {
    BitArray arr1(5, 0b10101);
    BitArray arr2 = arr1; // Проверяем копирующий конструктор
    EXPECT_EQ(arr2.size(), 5);
    EXPECT_TRUE(arr2[0]);
    EXPECT_FALSE(arr2[1]);

    BitArray arr3;
    arr3 = arr1; // Проверяем оператор присваивания
    EXPECT_EQ(arr3.size(), 5);
    EXPECT_TRUE(arr3[4]);
}

// Тест на изменение размера массива
TEST(BitArrayTest, Resize) {
    BitArray arr(5);
    arr.resize(10, true); // Увеличиваем размер и устанавливаем новые биты в 1
    EXPECT_EQ(arr.size(), 10);
    EXPECT_TRUE(arr[9]);
    arr.resize(3); // Уменьшаем размер
    EXPECT_EQ(arr.size(), 3);
}

// Тест для метода clear
TEST(BitArrayTest, Clear) {
    BitArray arr(10, 0b1111111111);
    arr.clear();
    EXPECT_EQ(arr.size(), 0);
    EXPECT_TRUE(arr.empty());
}

// Тест для метода push_back
TEST(BitArrayTest, PushBack) {
    BitArray arr(3, 0b101);
    arr.push_back(true);
    EXPECT_EQ(arr.size(), 4);
    EXPECT_TRUE(arr[3]);
    arr.push_back(false);
    EXPECT_EQ(arr.size(), 5);
    EXPECT_FALSE(arr[4]);
}

// Тест для побитовых операций
TEST(BitArrayTest, BitwiseOperations) {
    BitArray arr1(8, 0b10101010);
    BitArray arr2(8, 0b11001100);
    arr1 &= arr2; // Побитовое И
    EXPECT_EQ(arr1.to_string(), "10001000");

    arr1 |= arr2; // Побитовое ИЛИ
    EXPECT_EQ(arr1.to_string(), "11001100");

    arr1 ^= arr2; // Побитовое исключающее ИЛИ
    EXPECT_EQ(arr1.to_string(), "00000000");
}

// Тест на побитовые сдвиги
TEST(BitArrayTest, BitShifts) {
    BitArray arr(8, 0b11000011);
    arr <<= 2; // Логический сдвиг влево на 2
    EXPECT_EQ(arr.to_string(), "00001100");

    arr >>= 3; // Логический сдвиг вправо на 3
    EXPECT_EQ(arr.to_string(), "00000011");
}

// Тест для методов set и reset
TEST(BitArrayTest, SetAndReset) {
    BitArray arr(5);
    arr.set(2); // Устанавливаем 3-й бит
    EXPECT_TRUE(arr[2]);
    arr.reset(2); // Сбрасываем 3-й бит
    EXPECT_FALSE(arr[2]);
}

// Тест для методов any и none
TEST(BitArrayTest, AnyAndNone) {
    BitArray arr(5, 0);
    EXPECT_TRUE(arr.none()); // Проверяем, что все биты сброшены
    arr.set(3);
    EXPECT_TRUE(arr.any());  // Проверяем, что есть установленные биты
    arr.reset(3);
    EXPECT_TRUE(arr.none()); // Проверяем, что снова все сброшены
}

// Тест для метода count
TEST(BitArrayTest, Count) {
    BitArray arr(10, 0b1111000011);
    EXPECT_EQ(arr.count(), 6); // Подсчитываем количество установленных битов
}

// Тест для метода to_string
TEST(BitArrayTest, ToString) {
    BitArray arr(8, 0b11001100);
    EXPECT_EQ(arr.to_string(), "11001100"); // Проверяем строковое представление
}
