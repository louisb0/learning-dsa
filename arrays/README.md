# arrays

**Note**: In our definition, an array has a fixed size. So, we do not shift elements at any point, meaning the operations are all O(1). [The implementation](./implementation/int_array.c) does differ from this as it was a bit more fun to write.

* A contiguous memory space, containing a set number of bytes. Not extensible without reallocations.
* The compiler can interpret the memory space in many different ways - walk in 8bit, 6bit, 32bit?
    * `addr(array) + sizeof(array_type)*index`
* Operations:
    * Get at index - read from memory using above idea. `O(1)`
    * Insert at index - overwrite at address using above idea. `O(1)`
    * Delete at index - set to 0 at address using above idea. `O(1)`

**Example: Interpeting memory**

```
> const x = new ArrayBuffer(4);
undefined
> x
ArrayBuffer { [Uint8Contents]: <00 00 00 00>, byteLength: 4 }
> const x8 = new Uint8Array(x);
undefined
> x8[0] = 45
45
> x
ArrayBuffer { [Uint8Contents]: <2d 00 00 00>, byteLength: 4 }
> x8[2] = 45
45
> x
ArrayBuffer { [Uint8Contents]: <2d 00 2d 00>, byteLength: 4 }
> const x16 = new Uint16Array(x);
undefined
> x16[1] = 45
45
> x
ArrayBuffer { [Uint8Contents]: <2d 00 2d 00>, byteLength: 4 }
```

We can see when 'interpreting' the slots of memory 1 byte at a time, we have 4 slots. When interpreting this as 2 bytes, we reduce down to 2 slots - i.e. `x16[1]` and `x8[2]` refer to the same memory address (`16 * 1 = 16`, `8 * 2 = 16`).