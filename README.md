# Offsets 

## Objectives

- Gain experience with struct representation, layout, and alignment.
- (Optional) Gain experience with pointer arithmetic.

## Overview

Every C `struct` is represented as block of memory that is big enough to hold all of the fields.   Each field resides at a specific byte offset from the base of the structure.  This lab asks you to write code to determine the byte offsts of named fields of indexed elements in a one-dimensional array of structs.

In any C array, the elements are packed together in contiguous memory in ascending index/address order.   Therefore, in an array of structs, the offset of a field in element *k* is easily determined given the sizeof the struct and the field offsets in the struct.   It is *(k*size)+offset*.

Compilers follow strict conventions to determine the layout (field offsets) of a declared structure in memory.   The conventions are specified to ensure that separately compiled code objects agree on the layout, and address the fields at the same computed offsets. 

- Fields are ordered according to the declaration even if another ordering could yield a more compact layout.

- The offset of each field is properly aligned, i.e., the offset is evenly divisible by the sizeof the field.

- Padding (unused bytes) is inserted between fields as necessary to maintain this alignment.

- Padding is added at the end of the structure as needed to ensure the sizeof the structure is an even multiple of its longest field.   This constraint is necessary to maintain alignment of multiple instances of the structure in an array.

## `offsets_student.c`

This lab ask you to fill in the body of some functions in the source file `offsets_student.c`. Each function corresponds to a specific struct declared in `structs.h`.   It returns the byte offset of field `fieldIndex` in the struct at array index `arrayIndex` in an array of that struct.

The structs' definitions are included in `structs.h`.   Please do not modify them.   All structs have the same number of elements with the same names, but various types.

For example, function `offsetsS1` computes offsets for an array of elements of type `struct S1`.   Your function computes the byte offset of field number `fieldIndex` in the element at index `arrayIndex`in the array.   Like `arrayIndex`, `fieldIndex` is 0-indexed: the first element or field has index 0.

It is not necessary or possible for your code to apply the layout rules to the struct declarations.   One option is to apply the rules in your head and determine the byte offset of each of the fields, and incorporate those offsets (16 of them) as constants into your code.   Another option is to do some fancy pointer arithmetic.

For example, if the struct is defined as:

```c
struct S1 {
    int f0;
    char f1;
    int f2;
};
```

Then the struct size is 12 bytes and the byte offset of the `f1` field at index 5 of the array (the sixth element) is: 60 + 4 = 64.

### Local Testing and Submission

1. Fork, clone, cd, etc., as usual, and run `make` to build.

2. Test certain function:

```bash
./offsets <struct index> <array index> <field index>
```

3. Run the local Python test script by running the following on the Unix command
   line:
   ```bash
   python3 test_kit.py ALL
   ```
   If all tests are passing, they should also pass on Gradescope. If a test is
   failing, you can see exactly which one and find its corresponding input file
   in the `tests` folder for further debugging.

   It is important that the output of your program matches exactly what is shown
   in the description above (this are also provided in the
   `tests/*_expected_*.txt` files).

4. Add, commit, and push your file to your git repo:

    * `offsets_student.c`
	* `statement.txt`

5. Submit to Gradescope. 
