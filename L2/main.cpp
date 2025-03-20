#include <iostream>
#include "vector3.hpp"
#include <cstddef> // For std::byte
#include <vector>

void print_readable_character(std::byte byte)
{
    if (byte >= std::byte{0x20} && byte <= std::byte{0x7E})
        std::cout << static_cast<char>(byte);
    else
        std::cout << ".";  // Non-readable character cannot be shown in the console
}

void dump_memory(std::byte* start, size_t count)
{
    const long int window_width = 8;

    // Print the memory address
    std::cout << start << ":" << std::hex << reinterpret_cast<uintptr_t>(start) << "|";

    // Print the memory content as bytes
    for (size_t i = 0; i < count; i++) {
        if (i % window_width == 0 && i != 0) {
            std::cout << " |"; // End of the current window
            std::cout << "\n" << start + i << ":" << std::hex << reinterpret_cast<uintptr_t>(start + i) << "|";
        }
        std::cout << " " << std::hex << static_cast<int>(start[i]);
    }

    std::cout << " |" << std::endl;
}

int main()
{
    std::cout << "STAGE 1" << std::endl;

    // STAGE 1: Instantiate a Vector3 here
    l2::Vector3 b1, b2, b3;
    b1.v.x = 1;
    b1.v.y = 0;
    b1.v.z = 0;

    b2.v.x = 0;
    b2.v.y = 1;
    b2.v.z = 0;

    b3.v.x = 0;
    b3.v.y = 0;
    b3.v.z = 1;

    std::cout << "STAGE 2 and 3" << std::endl;

    const int array_size = 10;
    // STAGE 2: stack, heap, and std::vector
    l2::Vector3 stack_T[array_size];
    l2::Vector3* ptr2heap = new l2::Vector3[array_size];
    std::vector<l2::Vector3> v_arr(array_size);

    for (int i = 0; i < array_size; i++) {
        l2::Vector3 new_v;
        new_v.v.x = i;
        new_v.v.y = i;
        new_v.v.z = i;

        stack_T[i] = new_v;
        ptr2heap[i] = new_v;
        v_arr[i] = new_v;

        std::cout << "Vector " << i << " length: " << new_v.length() << std::endl;
    }

    // Dump memory of stack_T
    std::cout << "Dumping stack_T memory:" << std::endl;
    dump_memory(reinterpret_cast<std::byte*>(stack_T), sizeof(stack_T));

    // Dump memory of ptr2heap
    std::cout << "Dumping ptr2heap memory:" << std::endl;
    dump_memory(reinterpret_cast<std::byte*>(ptr2heap), array_size * sizeof(l2::Vector3));

    // Dump memory of v_arr
    std::cout << "Dumping v_arr memory:" << std::endl;
    dump_memory(reinterpret_cast<std::byte*>(v_arr.data()), v_arr.size() * sizeof(l2::Vector3));

    // Free heap memory
    delete[] ptr2heap;

    std::cout << "STAGE 4" << std::endl;

    // STAGE 4: HoleyString should be created here

    std::cout << "STAGE 5" << std::endl;

    // STAGE 5: Test your memcpy and memmove implementations here

    return 0;
}