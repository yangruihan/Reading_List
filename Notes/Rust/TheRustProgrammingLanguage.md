# Basic

ref: https://doc.rust-lang.org/stable/book/

## Table of Contents

- [Basic](#basic)
  - [Table of Contents](#table-of-contents)
  - [cargo command](#cargo-command)
  - [variables and mutability](#variables-and-mutability)
    - [const vs immutable variables](#const-vs-immutable-variables)
    - [shadow vs mutable variables](#shadow-vs-mutable-variables)
  - [Data Types](#data-types)
    - [Scalar Types](#scalar-types)
      - [Integer Types](#integer-types)
      - [Floating-Point Types](#floating-point-types)
      - [Boolean Type](#boolean-type)
      - [The Character Type](#the-character-type)
    - [Compound Types](#compound-types)
      - [The Tuple Type](#the-tuple-type)
      - [The Array Type](#the-array-type)
  - [Functions](#functions)
    - [Expression and Statement](#expression-and-statement)
    - [Functions with Return Values](#functions-with-return-values)
  - [Control Flow](#control-flow)
    - [`if` Expression](#if-expression)
      - [Using `if` in a let Statement](#using-if-in-a-let-statement)
    - [Loops](#loops)
      - [Returing Values from Loops](#returing-values-from-loops)
  - [Ownership](#ownership)
    - [Ownership](#ownership-1)
      - [Ownership Rules](#ownership-rules)
      - [Ways Variables and Data Interact: Move](#ways-variables-and-data-interact-move)
      - [Ways Variables and Data Interact: Clone](#ways-variables-and-data-interact-clone)
      - [Stack-Only Data: Copy](#stack-only-data-copy)
      - [Ownership and Functions](#ownership-and-functions)
      - [Return Values and Scope](#return-values-and-scope)
    - [References and Borrowing](#references-and-borrowing)
      - [Mutable References](#mutable-references)
      - [Dangling References](#dangling-references)
    - [Slice](#slice)
      - [String Slices](#string-slices)
      - [Other Slices](#other-slices)
  - [Structs](#structs)
    - [Defening and Instantiating Structs](#defening-and-instantiating-structs)
    - [Tuple Struct](#tuple-struct)
    - [Unit-Like structs without any fields](#unit-like-structs-without-any-fields)
    - [Method Syntax](#method-syntax)
    - [Assiciated Functions](#assiciated-functions)
  - [Enums and Pattern Matching](#enums-and-pattern-matching)
    - [Defining an Enum](#defining-an-enum)
    - [Defining an Enum with data](#defining-an-enum-with-data)
    - [The `match` Control flow operator](#the-match-control-flow-operator)
    - [Concise control flow with `if let`](#concise-control-flow-with-if-let)
  - [Managing Growing Projects with Packages, Crates and Modules](#managing-growing-projects-with-packages-crates-and-modules)
    - [Packages and Crates](#packages-and-crates)
    - [Modules](#modules)
    - [Paths](#paths)
    - [Privacy](#privacy)
    - [Making Structs and Enums Public](#making-structs-and-enums-public)
    - [`use` keyword](#use-keyword)
    - [Separating Modules into Different Files](#separating-modules-into-different-files)
  - [Common Collections](#common-collections)
    - [Vector](#vector)
    - [String](#string)
    - [HashMap](#hashmap)
  - [Error Handling](#error-handling)
    - [Unrecoverable Errors with `panic!`](#unrecoverable-errors-with-panic)
    - [Recoverable Errors with `Result`](#recoverable-errors-with-result)
    - [Propagating Errors](#propagating-errors)
    - [To `panic!` or Not to `panic!`](#to-panic-or-not-to-panic)
  - [Generic Types, Traits, and Lifetimes](#generic-types-traits-and-lifetimes)
    - [Generic Data Types](#generic-data-types)
    - [Traits: Defining Shared Behavior](#traits-defining-shared-behavior)
      - [Defining a Trait](#defining-a-trait)
      - [Implementing a Trait on a Type](#implementing-a-trait-on-a-type)
      - [Default Implementations](#default-implementations)
      - [Traits as Parameters](#traits-as-parameters)
      - [Specifying Multiple Trait Bounds with the `+` Syntax](#specifying-multiple-trait-bounds-with-the--syntax)
      - [Clearer Trait Bounds with `where` Clauses](#clearer-trait-bounds-with-where-clauses)
      - [Returning Types that Implement Traits](#returning-types-that-implement-traits)
      - [Using Trait Bounds to Conditionally Implement Methods](#using-trait-bounds-to-conditionally-implement-methods)
    - [Validating References with Lifetimes](#validating-references-with-lifetimes)
      - [Lifetime Annotation Syntax](#lifetime-annotation-syntax)
      - [Lifetime Annotations in Struct Definitions](#lifetime-annotations-in-struct-definitions)
      - [Lifetime Elision](#lifetime-elision)
      - [Lifetime Annotations in Method Definitions](#lifetime-annotations-in-method-definitions)
      - [The Static Lifetime](#the-static-lifetime)
  - [Writing Automated Tests](#writing-automated-tests)
    - [How to write tests](#how-to-write-tests)
      - [Checking results with the `assert!` macro](#checking-results-with-the-assert-macro)
      - [Testing equality with the `assert_eq!` and `assert_ne!` macros](#testing-equality-with-the-assert_eq-and-assert_ne-macros)
      - [Checking for panic with `should_panic`](#checking-for-panic-with-should_panic)
      - [Using `Result<T, E>` in tests](#using-resultt-e-in-tests)
    - [Controlling how tests are run](#controlling-how-tests-are-run)
    - [Test organization](#test-organization)
  - [Functional Language Features: Iterators and Closures](#functional-language-features-iterators-and-closures)
    - [Closure](#closure)
      - [Defining a closure](#defining-a-closure)
      - [Storing Closures Using Generic Parameters and the `Fn` Traits](#storing-closures-using-generic-parameters-and-the-fn-traits)
      - [Capturing the Environment with Closures](#capturing-the-environment-with-closures)
    - [Iterators](#iterators)
      - [Processing a Series of Items with Iterators](#processing-a-series-of-items-with-iterators)
      - [Methods that Consume the iterator](#methods-that-consume-the-iterator)
      - [Methods that Produce Other Iterators](#methods-that-produce-other-iterators)
      - [Creating Our Own Iterator with the `Iterator` Trait](#creating-our-own-iterator-with-the-iterator-trait)
      - [Comparing Performance: Loops vs. Iterators](#comparing-performance-loops-vs-iterators)
  - [More About Cargo and Crates.io](#more-about-cargo-and-cratesio)
    - [Publising a Crate to Crates.io](#publising-a-crate-to-cratesio)
      - [Making Useful Documentation Comments](#making-useful-documentation-comments)
      - [Documentation Comments as Tests](#documentation-comments-as-tests)
      - [Commenting Contained Items](#commenting-contained-items)
  - [Smart Pointers](#smart-pointers)
    - [Using `Box<T>` to Point to Data on the Heap](#using-boxt-to-point-to-data-on-the-heap)
      - [Using a `Box<T>` to Store Data ont the Heap](#using-a-boxt-to-store-data-ont-the-heap)
    - [Treating Smart Pointers Like Regular References with `Deref` Trait](#treating-smart-pointers-like-regular-references-with-deref-trait)
    - [Implicit Deref Coercions with Functions and Methods](#implicit-deref-coercions-with-functions-and-methods)
    - [How Deref Coercion Interacts with Mutability](#how-deref-coercion-interacts-with-mutability)
    - [Running Code on Cleanup with the `Drop` Trait](#running-code-on-cleanup-with-the-drop-trait)
    - [Dropping a Value Early with `std::mem::drop`](#dropping-a-value-early-with-stdmemdrop)
    - [`Rc<T>`, the Reference Counted Smart Pointer](#rct-the-reference-counted-smart-pointer)
    - [`RefCell<T>` and the Interior Mutability Pattern](#refcellt-and-the-interior-mutability-pattern)
    - [Reference Cycles Can Leak Memory](#reference-cycles-can-leak-memory)
  - [Fearless Concurrency](#fearless-concurrency)
    - [Using Threads to Run Code Simultaneously](#using-threads-to-run-code-simultaneously)
    - [Using Message Passing to Transfer Data Between Threads](#using-message-passing-to-transfer-data-between-threads)
    - [Shared-State Concurrency](#shared-state-concurrency)
    - [Extensible Concurrency with the `Sync` and `Send` Traits](#extensible-concurrency-with-the-sync-and-send-traits)
  - [Object Oriented Programming Features of Rust](#object-oriented-programming-features-of-rust)
    - [Characteristics of Object-Oriented Languages](#characteristics-of-object-oriented-languages)
    - [Using Trait Objects that allow for values of different types](#using-trait-objects-that-allow-for-values-of-different-types)
    - [Implementing an Object-Oriented Design Pattern](#implementing-an-object-oriented-design-pattern)
  - [Patterns and Matching](#patterns-and-matching)
    - [All the places patterns can be used](#all-the-places-patterns-can-be-used)
      - [`match` arms](#match-arms)
      - [Conditional `if let` expressions](#conditional-if-let-expressions)
      - [`while let` conditional loops](#while-let-conditional-loops)
      - [`for` loops](#for-loops)
      - [`let` statements](#let-statements)
      - [Function parameters](#function-parameters)
    - [Refutability: Whether a pattern migth fall to match](#refutability-whether-a-pattern-migth-fall-to-match)
    - [Pattern Syntax](#pattern-syntax)
      - [Matching Literals](#matching-literals)
      - [Matching Named Variables](#matching-named-variables)
      - [Multiple Patterns](#multiple-patterns)
      - [Matching Ranges of Values with `..=`](#matching-ranges-of-values-with-)
      - [Destructuring to Break Apart Values](#destructuring-to-break-apart-values)
      - [Ignoring Values in a Pattern](#ignoring-values-in-a-pattern)
      - [Extra Conditionals with Match Guards](#extra-conditionals-with-match-guards)
      - [`@Bindings`](#bindings)
  - [Advanced Features](#advanced-features)
    - [Unsafe Rust](#unsafe-rust)
      - [Dereferencing a raw pointer](#dereferencing-a-raw-pointer)
      - [Calling an unsafe function or method](#calling-an-unsafe-function-or-method)
      - [Creating a safe abstraction over unsafe code](#creating-a-safe-abstraction-over-unsafe-code)
      - [Using `extern` functions to call external code](#using-extern-functions-to-call-external-code)
      - [Accessing or modifying a mutable static variable](#accessing-or-modifying-a-mutable-static-variable)
      - [Implementing an unsafe trait](#implementing-an-unsafe-trait)
      - [Accessing fields of a union](#accessing-fields-of-a-union)
    - [Advanced Traits](#advanced-traits)
      - [Specifying placeholder types in trait definition with associated types](#specifying-placeholder-types-in-trait-definition-with-associated-types)
      - [Default generic type parameters and operator overloading](#default-generic-type-parameters-and-operator-overloading)
      - [Fully qualified syntax for disambiguation: call methods with the same name](#fully-qualified-syntax-for-disambiguation-call-methods-with-the-same-name)
      - [Using supertraits to require one trait's functionality within another trait](#using-supertraits-to-require-one-traits-functionality-within-another-trait)
      - [Using the newtype pattern to implement external traits on external types](#using-the-newtype-pattern-to-implement-external-traits-on-external-types)
    - [Advanced Types](#advanced-types)
      - [Creating Type Synonyms with Type Aliases](#creating-type-synonyms-with-type-aliases)
      - [The Never Type that Never Returns](#the-never-type-that-never-returns)
      - [Dynamically Sized Types and the Sized Trait](#dynamically-sized-types-and-the-sized-trait)
    - [Advanced Functions and Closures](#advanced-functions-and-closures)
      - [Function Pointers](#function-pointers)
      - [Returning Closures](#returning-closures)
    - [Macros](#macros)
      - [The difference between macros and functions](#the-difference-between-macros-and-functions)
      - [Delcarative macros with `macro_rules!` for general metaprogramming](#delcarative-macros-with-macro_rules-for-general-metaprogramming)
      - [Procedural macros for generating code from attributes](#procedural-macros-for-generating-code-from-attributes)

## cargo command

- `cargo build`: build a project
- `cargo run`: build and run a project in one step
- `cargo check`: build a project without producing a binary to check for errors
- `cargo build --release`: build for release version
- `cargo run --release`: build and run a project with release version

## variables and mutability

- default variables are **immutable**
- make variables mutable by adding `mut`

### const vs immutable variables
1. Don't allow to use `mut` with constants. Constants aren't just immutable by default -- they're always immutable.
2. Constants can be declared in **any scope**, including the global scope.
3. Constants may be set only to a constant expression.

*Rust's naming convention for constants is to use all **uppercase with underscores between words**, and underscores can be inserted in numeric literals to improve readability.*

```rust
const MAX_POINT: u32 = 100_000;
```

### shadow vs mutable variables
1. We'll get a **compile-error** if we accidentally try to reassign to the variable without using the `let` keyword.
2. By using `let`, we can perform a few transformations on a value but have the variable be **immutable** after those transformations have been completed.
3. We can change the type of the value but reuse the same name.

## Data Types
- Rust is a **statically typed** language.

### Scalar Types
- A **scalar** type represents a single value.
- Four primary scalar types: **integers**, **floating-point numbers**, **Booleans**, **characters**.

#### Integer Types

| Length          | Signed | Unsigned |
| :-------------- | :----- | :------- |
| 8-bit           | i8     | u8       |
| 16-bit          | i16    | u16      |
| 32-bit(default) | i32    | u32      |
| 64-bit          | i64    | u64      |
| 128-bit         | i128   | u128     |
| arch            | isize  | usize    |

*Signed numbers are stored using two's complement representation*

Integer Literals in Rust:

| Number literals | Example     |
| :-------------- | :---------- |
| Decimal         | 98_222      |
| Hex             | 0xff        |
| Octal           | 0o77        |
| Binary          | 0b1111_0000 |
| Byte(u8 only)   | b'A'        |

#### Floating-Point Types

- `f32`
- `f64`(default)

#### Boolean Type

- `true`
- `false`

```rust
let t = true;
let f: bool = false;
```

#### The Character Type

- Use **single quotes**.
- **Four bytes** in size and represents a Unicode Scalar Value.

### Compound Types

#### The Tuple Type

- Group together a number of values with a **variety of types** into one compound type.
- Have a **fixed length**: once declared, they cannot grow or shrink in size.

```rust
// create a tuple
let tup: (i32, f64, u8) = (500, 6.4, 1);

// destructuring
let (x, y, z) = tup;

// access with index
let five_hundred = tup.0;
let six_point_four = tup.1;
let one = tup.2;
```

#### The Array Type

- Every element of an array must have the **same type**.
- Fixed length like tuples.
- Raise a *runtime* error at the point of using an invalid value in the indexing operation.

```rust
let a = [1, 2, 3, 4, 5];
let a: [i32; 5] = [1, 2, 3, 4, 5];
let a = [3; 5]; // ==> let a = [3, 3, 3, 3, 3];

let first = a[0];
let second = a[1];
```

## Functions

- Rust code uses *snake* case as the conventional style for function and variable names.
- Rust doesn't care about where you define your functions, only that they're defined somewhere.
- **Must** declare the type of each parameter.

### Expression and Statement

- Rust is an **expression-based** language.
- **Statements** are instructions that perform some action and do not return a value.
- **Expressions** evaluate to a resulting value.
- Calling a function is an expression. Calling a macro is an expression. The block that we use to create new scopes, `{}`, is an expression.

    ```rust
    fn main() {
        let x = 5;

        let y = {
            let x = 3;
            x + 1 // without a semicolon
        };
    }
    ```

### Functions with Return Values

- In Rust, the return value of the function is synonymous with the value of the final expression in the block of the body of a function.
- Use `return` keyword and specifying s value to return early from a expression.

    ```rust
    fn five() {
        5
    }
    ```

## Control Flow

### `if` Expression

- Condition must be a bool. If the condition isn't a bool, we'll get an error.
- RUst will not automatically try to convert non-Boolean types to a Boolean.

```rust
fn main() {
    let number = 3;

    if number < 5 {
        println!("condition wae true");
    } else {
        println!("condition wae false");
    }
}
```

#### Using `if` in a let Statement

```rust
let condition = true;
let number = if condition { 5 } else { 6 };
```

### Loops

- `loop`

    ```rust
    loop {
        println!("again!");
    }
    ```

- `while`

    ```rust
    let mut n = 3;
    while n != 0 {
        println!("{}!", n);
        n -= 1;
    }
    ```

- `for`

    ```rust
    let a = [10, 20, 30, 40, 50];
    for element in a.iter() {
        println!("the value is: {}", element);
    }
    ```

    *Faster than `while` version, becaure it won't check index every iteration.*

    ```rust
    for number in (1..4).rev() {
        println!("{}!", number);
    }
    ```

#### Returing Values from Loops

```rust
let result = loop {
    counter += 1;
    if counter == 10 {
        break counter * 2;
    }
};
```

## Ownership

### Ownership

#### Ownership Rules

- Each value in Rust has a variable that's called its owner.
- There can only be one owner at a time.
- When the owner goes out of scope, the value will be dropped.

- When variable goes out of scop, Rust calls a special function for us, called `drop`.

#### Ways Variables and Data Interact: Move

- copy only stack memory
- Rust will never automatically create "deep" copies of your data.

```rust
let s1 = String::from("hello");
let s2 = s1; // move

// println!("{}", s1); // error! s1 is no longer valid
println!("{}", s2); // ok
```

#### Ways Variables and Data Interact: Clone

- copy both stack and heap memory

```rust
let s1 = String::from("hello");
let s2 = s1.clone(); // clone

println!("s1 = {}, s2 = {}", s1, s2);
```

#### Stack-Only Data: Copy

- Rust won't let us annotate a type with the **Copy trait** if the type, or any of its parts, has implemented the **Drop trait**.
- Here are some of the types that implement Copy:

    - All the integer types, such as u32.
    - The Boolean type, bool, with values true and false.
    - All the floating point types, such as f64.
    - The character type, char.
    - Tuples, if they **only** contain types that also implement Copy.

#### Ownership and Functions

- Passing a variable to a function will move or copy, just as assignment does.

```rust
fn main() {
    let s = String::from("hello"); // s comes in scope

    takes_ownership(s); // s's value moves into the function
                        // and so is no longer valid here

    let x = 5;          // x comes into scope

    makes_copy(x);      // x would move into the function
                        // but i32 is Copy, so it's okay to still use x afterward
}

fn takes_ownership(some_string: String) { // some_string comes into scope
    println!("{}", some_string);
} // Here, some_string goes out of scope and `drop` is called. The backing memory is freed.

fn makes_coy(some_integer: i32) { // some_integer comes into scope
    println!("{}", some_integer);
} // Here, some_integer goe out of scope. Nothing special happens.
```

#### Return Values and Scope

- The ownership of a variable follows the same pattern everty time: assigning a value to another variable moves it. When a variable that includes data on the heap goes out of scope, the value will be cleaned up by drop unless the data has been moved to be owned by another variable.

```rust
fn main() {
    let s1 = gives_ownership(); // gives_ownership moves its return value into s1

    let s2 = String::from("hello"); // s2 comes into scope

    let s3 = takes_and_gives_back(s2); // s2 is moved into takes_and_gives_back,
                                       // which also moves its return value into s3
} // Here, s3 goes out of scope and is dropped. s2 goes out of scope but was moved,
// so nothing happens. s1 goes out of scope and is dropped.

fn gives_ownership() -> String { // gives_ownership will move its return value into
                                 // the function that calls it

    let some_string = String::from("hello"); // some_string come into scope

    some_string // some_string is returned and moves out to the calling function
}

// takes_and_gives_back will take a String and return one
fn takes_and_gives_back(a_string: String) -> String { // a_string comes into scope
    a_string // a_string is returned and moves out to the calling function
}
```
### References and Borrowing

- Reference parameter will not be dropped when it goes out of scope, because we don't have ownership.
- Call having references as function parameters borrowing.
- Just as variables are immutable by default, so are references. We're not allowed to modify something we have a reference to.

```rust
fn main() {
    let s1 = String::from("hello");

    let len = calculate_length(&s1);

    println!("The length of '{}' is {}.", s1, len);
}

fn calculate_length(s: &String) -> usize {
    s.len()
}
```

#### Mutable References

- You can have **only one** mutable reference to a particular piecee of data in a particular scope. (prevent data races at compile time)

```rust
fn main() {
    let mut s = String::from("hello");

    change(&mut s);
}

fn change(some_string: &mut String) {
    some_string.push_str(", world");
}
```

- We can use curly brackets to create a new scope, allowing for multiple mutable references.

```rust
fn main() {
    let mut s = String::from("hello");

    {
        let r1 = &mut s;
    } // r1 goes out of scope here, so we can make a new reference with no problems.

    let r2 = &mut s;
}
```

- We also cannot have a mutable reference while we have an immutable one.
- Multiple immutable references are okay.
- A reference's scope starts from where it is introduced and continues through the last time that references is used.

```rust
fn main() {
    let mut s = String::from("hello");

    let r1 = &s; // no problem
    let r2 = &s; // no problem

    println!("{} and {}", r1, r2);
    // variables r1 and r2 will not used after this point

    let r3 = &mut s; // no problem
    println!("{}", r3);

    // println!("{}", r1); // error!
    // mutable reference cannot be used while have an immutable
    // reference one
}
```

#### Dangling References

- Compiler guarantees that references will never be dangling references: if you have a reference to some data, the compiler will ensure that the data will not go out of scope before the reference to the data does.

### Slice

- Slices let you reference a contiguous sequence of elements in a collection rather than the whole collection.

#### String Slices

- A **string slice** is a reference to part of a String.

```rust
fn main() {
    let s = String::from("hello world");
    let hello = &s[0..5]; // ==> let hello = &s[..5];
    let world = &s[6..11]; // ==> let world = &s[6..];
    let whole_string = &s[...];
}
```

- String slice range indices must occur at valid UTF-8 character boundaries. If you attempt to create a string slice in the middle of a multibyte character, your program will exit with an error.

#### Other Slices

- There's a more general slice type.

```rust
#![allow(unused)]
fn main() {
let a = [1, 2, 3, 4, 5];

let slice = &a[1..3]; // type is &[i32]

assert_eq!(slice, &[2, 3]);
}

```

## Structs

### Defening and Instantiating Structs

- Basic define and use.

    ```rust
    struct User {
        username: String,
        email: String,
        sign_in_count: u64,
        active: bool,
    }

    fn main() {
        let user1 = User {
            email: String::from("someone@example.com"),
            username: String::from("someusername123"),
            active: true,
            sign_in_count: 1,
        };
    }
    ```

- Using the Field Init Shorthand when variables and Fields have the same name.

    ```rust
    fn build_user(email: String, username: String) -> User {
        User {
            email,
            username,
            active: true,
            sign_in_count: 1,
        }
    }
    ```

- Creating instances from other instances with struct update syntax.

    ```rust
    fn main() {
        let user1 = User {
            email: String::from("someone@example.com"),
            username: String::from("someusername123"),
            active: true,
            sign_in_count: 1,
        };

        let user2 = User {
            email: String::from("another@example.com"),
            username: String::from("anotherusername567"),
            ..user1
        };
    }
    ```

### Tuple Struct

- Tuple structs have the added meaning the struct name provides but don’t have names associated with their fields; rather, they just have the types of the fields.

```rust
fn main() {
    struct Color(i32, i32, i32);
    struct Point(i32, i32, i32);

    let black = Color(0, 0, 0);
    let origin = Point(0, 0, 0);
}
```

### Unit-Like structs without any fields

- These are called unit-like structs because they behave similarly to (), the unit type.

### Method Syntax

```rust
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }
}
```

### Assiciated Functions

Another useful feature of impl blocks is that we’re allowed to define functions within impl blocks that don’t take self as a parameter.


## Enums and Pattern Matching

### Defining an Enum

```rust
enum IpAddrKind {
    V4,
    V6,
}

fn main() {
    let four = IpAddrKind::V4;
    let six = IpAddrKind::V6;

    route(IpAddrKind::V4);
    route(IpAddrKind::V6);

    route(four);
    route(six);
}

fn route(ip_kind: IpAddrKind) {}
```

### Defining an Enum with data

```rust
fn main() {
    enum IpAddr {
        V4(String),
        V6(String),
    }

    let home = IpAddr::V4(String::from("127.0.0.1"));

    let loopback = IpAddr::V6(String::from("::1"));
}
```

- There’s another advantage to using an enum rather than a struct: each variant can have different types and amounts of associated data.

```rust
fn main() {
    enum IpAddr {
        V4(u8, u8, u8, u8),
        V6(String),
    }

    let home = IpAddr::V4(127, 0, 0, 1);

    let loopback = IpAddr::V6(String::from("::1"));
}
```

- Option Enum

```rust
enum Option<T> {
    None,
    Some(T),
}
```

### The `match` Control flow operator

- Patterns an be made up of **literal values**, **variable names**, **wildcards**, and many other things.

- Matches in Rust are exhaustive: we must exhaust every last possibility in order for the code to be valid

```rust
enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter,
}

fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => 1,
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter => 25,
    }
}
```

- The `_` pattern will match any value.

### Concise control flow with `if let`

```rust
fn main() {
    let some_u8_value = Some(0u8);
    match some_u8_value {
        Some(3) => println!("three"),
        _ => println!("other"),
    }
}

fn main() {
    let some_u8_value = Some(0u8);
    if let Some(3) = some_u8_value {
        println!("three");
    } else {
        println!("other");
    }
}
```

## Managing Growing Projects with Packages, Crates and Modules

- **Module System**:

    - **Packages**: A Cargo feature that lets you build, test, and share crates
    - **Crates**: A tree of modules that produces a library or executable
    - **Modules** and **use**: Let you control the organization, scope and privacy of paths
    - **Paths**: A way of naming an item, such as a struct, function or module

### Packages and Crates

- A **crate** is a binary or library.

    - The *crate root* is a source file that the Rust compiler starts from and makes up the root module of your crate.

- A **package** is one or more crates that provide a set of functionality.

    - A package contains a *Cargo.toml* file that describes how to build those crates.

    - A package can contain at most one library crate. It can contain as many library crates as you'd like, but it must contain as least one crate (either library or binary).

    - *src/main.rs*: the crate root of a binary crate with the same name as the package.

    - *src/lib.rs*: the crate root of a library crate with the same name as the package.


    - A package can have multiple binary crates by placing files in the *src/bin* directory: each file will be a separate binary crate.

### Modules

- **Modules**

    1. let us organize code within a crate into groups for readability and easy reuse.
    2. control the *privacy* of items, which whether an item can be used by outside code(*public*) or is an internal implementation detail and not available for outside use(*private*).


- Define a module by starting with the `mod` keyword

### Paths

- A **Path** can take two forms:

    - An *absolute path* starts from a crate root by using a crate name or a literal `crate`.
    - A *relative path* starts from the current module and uses `self`, `super` or an identifier in the current module.

### Privacy

- All items (functions, methods, structs, enums, modules, and constants) are **private** by default. Items in a parent module can't use the private items inside child modules, but items in child modules can use the items in their ancestor modules.

### Making Structs and Enums Public

- If we use `pub` before a struct definition, we make the struct public, but the struct's fields will still be private. We can make each field public or not on a case-by-case basis.

- If we make an enum public, all of its variants are then public.

### `use` keyword

- We can bring a path into a scope once and then call the items in that path as if they're local items with the `use` keyword.

- You can also bring an item into scope with `use` and a relative path.

- Providing new names with the `as` keyword.

- Re-exporting names with `pub use`

- Using nested paths to clean up large `use` lists: `use std::io::{self, Write};`.

- The glob operator: `use std::collections::*;`

### Separating Modules into Different Files

- Using a semicolon after `mod abc` rather than using a block tells Rust to load the contents of the module from another file with the same name as the module.

## Common Collections

- Unlike the built-in array and tuple types, the data these collections point to is stored on the **heap**, which means the amount of data dose not need to be known at compile time and can grow or shrink as the program runs.

- Common collections

    - A **vector** allows you to store a variable number of values next to each other.
    - A **string** is a collection of characters.
    - A **hash map** allows you to associate a value with a particular key.

### Vector

- Vectors allow you to store more than one value in a single data structure that puts all the values next to each other in memory.

- Vectors can only store values of the same type.

    ```rust
    // ----- create a vector -----

    let v: Vec<i32> = Vec:new();

    let v = vec![1, 2, 3];

    // ----- updating a vector -----

    v.push(5);
    v.push(6);

    // ----- drop -----

    {
        let v = vec![1, 2, 3, 4];
        // do stuff with v
    } // <- v gose out of scope and is freed here

    // ----- get elements -----

    // index start at 0
    let third: &i32 = &v[2];

    match v.get(2) { // give Option<&i32>
        Some(third) => println!("The third element is {}", third),
        None => println!("There is no third element."),
    }

    // ----- iterating over the values in a vector -----

    let v = vec![100, 32, 57];
    for i in &v {
        println!("{}", i);
    }

    let mut v = vec![100, 32, 57];
    for i in &mut v {
        *i += 50;
    }

    // ----- using an enum to store multiple types -----

    enum SpreadsheetCell {
        Int(i32),
        Float(f64),
        Text(String),
    }

    let row = vec![
        SpreadsheetCell::Int(3),
        SpreadsheetCell::Text(String::from("blue")),
        SpreadsheetCell::Float(10.12),
    ];
    ```

### String

- Both `String` and string slices are UTF-8 encoded.

    ```rust
    // ----- create a new string -----

    let mut s = String::new();

    let data = "initial contents";

    let s = data.to_string();

    let s = "initial contents".to_string();

    let s = String::from("initial contents");

    // ----- updating a string -----

    let mut s = String::from("foo");
    s.push_str("bar");

    let mut s1 = String:from("foo");
    let s2 = "bar";
    s1.push_str(s2);
    s1.push('l')

    let s1 = String::from("Hello, ");
    let s2 = String::from("world!");
    let s3 = s1 + &s2; // note s1 has been moved here and can no longer be used
    // + operator uses the add method

    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");

    let s = format!("{}-{}-{}", s1, s2, s3); // doesn't take ownership of any of its parameters

    for c in "नमस्ते".chars() {
        println!("{}", c);
    }

    for b in "नमस्ते".bytes() {
        println!("{}", b);
    }

    ```

### HashMap

- Hash maps are homogeneous: all of the keys must have the same type, and all of the values must have the same type.

    ```rust
    use std::collections::HashMap;

    // ----- normal create -----

    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);

    // ----- create with iterators -----

    let teams = vec![String::from("Blue"), String::from("Yellow")];
    let initial_scores = vec![10, 50];

    let mut scores: HashMap<_, _> = teams.into_iter().zip(initial_scores.into_iter()).collect();

    // ----- ownership -----

    let field_name = String::from("Favorite color");
    let field_value = String::from("Blue");

    let mut map = HashMap::new();
    map.insert(field_name, field_value);
    // field_name and field_value are invalid at this point, try using them and
    // see what compiler error you get!

    // ----- accessing values -----

    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);

    let team_name = String::from("Blue");
    let score = scores.get(&team_name);

    // ----- iter ------

    for (key, value) in &scores {
        println!("{}: {}", key, value);
    }

    // ----- updating value -----

    // 1. overwriting a value
    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Blue"), 25);

    println!("{:?}", scores); // {"Blue": 25}

    // 2. only inserting a value if the key has no value
    scores.entry(String::from("Yellow")).or_insert(50);
    scores.entry(String::from("Blue")).or_insert(50);

    // 3. updating a value based on the old value
    let text = "hello world wonderful world";

    let mut map = HashMap::new();

    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        *count += 1;
    }
    ```

## Error Handling

### Unrecoverable Errors with `panic!`

- Can set `RUST_BACKTRACE` to 1 to get a backtrace of excatly what happened to cause the error. `RUST_BACKTRACE=1 cargo run`.

```rust
fn main() {
    panic!("crash and burn");
}
```

### Recoverable Errors with `Result`

- Like the `Option` enum, the `Result` enum and its variants have been brought into scope by the prelude.

```rust
enum Result<T, E> {
    Ok(T),
    Err(E),
}
```

- `unwrap`, return value inside the `Ok` while the `Result` value is the `Ok` variant, ohterwise `unwrap` will call the `panic!` macro.

    ```rust
    use std::fs::File;

    fn main() {
        let f = File::open("hello.txt").unwrap();
    }
    ```

- `expect` is similar to `unwrap`, let us also choose the `panic!` error message.

    ```rust
    use std::fs::File;

    fn main() {
        let f = File::open("hello.txt").expect("Failed to open hello.txt");
    }
    ```

### Propagating Errors

```rust
fn read_username_from_file() -> Result<String, io::Error> {
    let f = File::open("hello.txt");

    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut s = String::new();

    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
}
```

use `?` operator:

```rust
use std::fs::File;
use std::io;
use std::io::Read;

fn read_username_from_file() -> Result<String, io::Error> {
    let mut f = File::Open("hello.txt")?;
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    Ok(s)
}
```

use chain:

```rust
use std::fs::File;
use std::io;
use std::io::Read;

fn read_username_from_file() -> Result<String, io::Error> {
    let mut s = String::new();
    File::open("hello.txt")?.read_to_string(&mut s)?;
    Ok(s)
}
```

**The `?` Operator can be used in functions that return `Result`**


### To `panic!` or Not to `panic!`

- ref: https://doc.rust-lang.org/book/ch09-03-to-panic-or-not-to-panic.html

## Generic Types, Traits, and Lifetimes

### Generic Data Types

- In function

    ```rust
    fn largest<T>(list: &[T]) -> T {
        let mut largest = list[0];

        for &item in list {
            if item > largest {
                largest = item;
            }
        }

        largest
    }
    ```

- In struct definition

    ```rust
    struct Point<T, U> {
        x: T,
        y: U,
    }
    ```

- In enum definition

    ```rust
    enum Option<T> {
        Some(T),
        None,
    }
    ```

- In method definition

    ```rust
    struct Point<T> {
        x: T,
        y: T,
    }

    impl<T> Point<T> {
        fn x(&self) -> &T {
            &self.x
        }
    }
    ```

    Generic type parameters in a struct definition aren’t always the same as those you use in that struct’s method signatures.

    ```rust
    struct Point<T, U> {
        x: T,
        y: U,
    }

    impl<T, U> Point<T, U> {
        fn mixup<V, W>(self, other: Point<V, W>) -> Point<T, W> {
            Point {
                x: self.x,
                y: other.y,
            }
        }
    }
    ```

- **Rust accomplishes this by performing monomorphization of the code that is using generics at compile time. Monomorphization is the process of turning generic code into specific code by filling in the concrete types that are used when compiled. So we pay no runtime cost for using generics.**

### Traits: Defining Shared Behavior

Trait definitions are a way to group method signatures together to define a set of behaviors necessary to accomplish some purpose.

#### Defining a Trait

```rust
pub trait Summary {
    fn summarize(&self) -> String;
}
```

#### Implementing a Trait on a Type

```rust
pub trait Summary {
    fn summarize(&self) -> String;
}

pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

impl Summary for NewsArticle {
    fn summarize(&self) -> String {
        format!("{}, by {} ({})", self.headline, self.author, self.location)
    }
}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }
}
```

**One restriction to note with trait implementations is that we can implement a trait on a type only if either the trait or the type is local to our crate.**

#### Default Implementations

```rust
pub trait Summary {
    fn summarize(&self) -> String {
        String::from("(Read more...)")
    }
}

impl Summary for NewsArticle {}
```

#### Traits as Parameters

```rust
pub fn notify(item: &impl Summary) {
    println!("Breaking news! {}", item.summarize());
}
```

equivalent to:

```rust
pub fn notify<T: Summary>(item: &T) {
    println!("Breaking news! {}", item.summarize());
}
```

#### Specifying Multiple Trait Bounds with the `+` Syntax

```rust
pub fn notify(item: &(impl Summary + Display)) {
```

equivalent to:

```rust
pub fn notify<T: Summary + Display>(item: &T) {
```

#### Clearer Trait Bounds with `where` Clauses

```rust
fn some_function<T: Display + Clone, U: Clone + Debug>(t: &T, u: &U) -> i32 {
```

equivalent to:

```rust
fn some_function<T, U>(t: &T, u: &U) -> i32
    where T: Display + Clone,
          U: Clone + Debug
{
```

#### Returning Types that Implement Traits

```rust
fn returns_summarizable() -> impl Summary {
    Tweet {
        username: String::from("horse_ebooks"),
        content: String::from(
            "of course, as you probably already know, people",
        ),
        reply: false,
        retweet: false,
    }
}
```

#### Using Trait Bounds to Conditionally Implement Methods

```rust
use std::fmt::Display;

struct Pair<T> {
    x: T,
    y: T,
}

impl<T> Pair<T> {
    fn new(x: T, y: T) -> Self {
        Self { x, y }
    }
}

impl<T: Display + PartialOrd> Pair<T> {
    fn cmp_display(&self) {
        if self.x >= self.y {
            println!("The largest member is x = {}", self.x);
        } else {
            println!("The largest member is y = {}", self.y);
        }
    }
}
```

### Validating References with Lifetimes

- Every reference in Rust has a *lifetime*.

#### Lifetime Annotation Syntax

- Lifetime annotations don't change how long any of the references lives.

- Lifetime annotations describe the relationships of the Lifetimes of multiple references to each other without affecting the Lifetimes.

- Syntax: start with an apostrophe(`'`) and are usually all lowercase and very short.

    ```rust
    &i32            // a reference
    &'a u32         // a reference with an explicit lifetime
    &'a mut i32     // a mutable reference with an explicit lifetime
    ```


#### Lifetime Annotations in Struct Definitions

```rust
// This annotation means an instance of ImportantExcerpt can’t outlive the reference it holds in its part field.
struct ImportantExcerpt<'a> {
    part: &'a str,
}
```

#### Lifetime Elision

- Rules:

    1. each parameter that is a reference gets its own lifetime parameter
    2.  if there is exactly one input lifetime parameter, that lifetime is assigned to all output lifetime parameters
    3.  if there are multiple input lifetime parameters, but one of them is `&self` or `&mut self` because this is a method, the lifetime of `self` is assigned to all output lifetime parameters

#### Lifetime Annotations in Method Definitions

```rust
struct ImportantExcerpt<'a> {
    part: &'a str,
}

impl<'a> ImportantExcerpt<'a> {
    fn level(&self) -> i32 {
        3
    }
}

impl<'a> ImportantExcerpt<'a> {
    fn announce_and_return_part(&self, announcement: &str) -> &str {
        println!("Attention please: {}", announcement);
        self.part
    }
}
```

#### The Static Lifetime

One special lifetime we need to discuss is `'static`, which means that this reference can live for the entire duration of the program.

## Writing Automated Tests

### How to write tests

The bodies of test functions typically perform these three actions:

1. Set up any needed data or state.
2. Run the code you want to test.
3. Assert the results are what you expect.

Add `#[test]` on the line before `fn` to change a function into a test function.

#### Checking results with the `assert!` macro

```rust
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn larger_can_hold_smaller() {
        let larger = Rectangle {
            width: 8,
            height: 7,
        };
        let smaller = Rectangle {
            width: 5,
            height: 1,
        };

        assert!(larger.can_hold(&smaller));
    }
}
```

#### Testing equality with the `assert_eq!` and `assert_ne!` macros

```rust
pub fn add_two(a: i32) -> i32 {
    a + 2
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_adds_two() {
        assert_eq!(4, add_two(2));
    }
}
```

#### Checking for panic with `should_panic`

```rust
pub struct Guess {
    value: i32,
}

impl Guess {
    pub fn new(value: i32) -> Guess {
        if value < 1 || value > 100 {
            panic!("Guess value must be between 1 and 100, got {}.", value);
        }

        Guess { value }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    #[should_panic]
    fn greater_than_100() {
        Guess::new(200);
    }
}
```

#### Using `Result<T, E>` in tests

```rust
#[cfg(test)]
mod tests {
    #[test]
    fn it_works() -> Result<(), String> {
        if 2 + 2 == 4 {
            Ok(())
        } else {
            Err(String::from("two plus two does not equal four"))
        }
    }
}
```

### Controlling how tests are run

- use `--test-threads` to control the number of threads to use.
- use `--show-output` to tell Rust to also show the output of successful tests at the end
- use `cargo test testname` to run a specific test
- use `cargo test namepattern` to run a subset of tests
- use `#[ignore]` to make the test ignored, use `cargo test -- --ignored` to run only the ignored tests

### Test organization

- Unit Tests: small and more focused, testing one module in isolation at a time, and can test private interfaces
- Integration Tests: entirely external to your library and use your code in the same way any other external code would, using only the public interface and potentially exercising multiple modules per test

## Functional Language Features: Iterators and Closures

### Closure

#### Defining a closure

- Closures don't require you to annotate the types of the parameters or the return value.

```rust
let a_closure = |num| {
    num
};

let a_closure_with_type = |num: u32| -> u32 {
    num
};

let a_closure_without_brackets = |num| num;
```

#### Storing Closures Using Generic Parameters and the `Fn` Traits

```rust
struct Cacher<T>
where
    T : Fn(u32) -> u32,
{
    calculation: T,
    value: Option<u32>,
}
```

#### Capturing the Environment with Closures

```rust
fn main() {
    let x = 4;

    let equal_to_x = |z| z == x;

    let y = 4;

    assert!(equal_to_x(y));
}
```

- Closures can capture values from their environment in three ways:

    1. take ownership: `FnOnce` consumes the variables it captures from its enclosing scope, known as the closure's environment. To consume the captured variables, the closure must take ownership of these variables and move them into the closure when it is defined. The `Once` part of the name represents the fact that the closure can't take ownership of the same variables more than once, so it can be called only once.
    2. borrow mutably: `FnMut` can change the environment because it mutably borrows values.
    3. borrow immediately: `Fn` borrows values from the environment immutably.

- When you create a closure, Rust infers which trait to use based on how the closure uses the values from the environment.

### Iterators

#### Processing a Series of Items with Iterators

```rust
fn main() {
    let v1 = vec![1, 2, 3];

    let v1_iter = v1.iter();

    for val in v1_iter {
        println!("Got: {}", val);
    }
}
```

- All iterators implement a trait named `Iterator` that is defined in the standard library.

    ```rust
    pub trait Iterator {
        type Item;

        fn next(&mut self) -> Option<Self::Item>;

        // methods with default implementations elided
    }
    ```

- The `Iterator` trait only requires implementors to define one method: the `next` method, which returns one item of the iterator at a time wrapped in `Some` and, when iteration is over, returns `None`.

#### Methods that Consume the iterator

- Methods that call `next` are called *consuming adaptors*, like `sum`.

- You can find out about these methods by looking in the standard library API documentation for the `Iterator` trait.

#### Methods that Produce Other Iterators

- *Iterator adaptors* allow you to change iterators into different kinds of iterators.

#### Creating Our Own Iterator with the `Iterator` Trait

```rust
struct Counter {
    count: u32,
}

impl Counter {
    fn new() -> Counter {
        Counter { count: 0 }
    }
}

impl Iterator for Counter {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        if self.count < 5 {
            self.count += 1;
            Some(self.count)
        } else {
            None
        }
    }
}
```

#### Comparing Performance: Loops vs. Iterators

- Iterators are one of Rust's zero-cost abstractions, by which we mean using the abstraction imposes no additional runtime overhead.

- *Unrolling* is an optimization that removes the overhead of the loop controlling code and instead generates repetive code for each iteration of the loop.

## More About Cargo and Crates.io

- *Release profiles* are predefined and customizable profiles with different configurations that allow a programmer to have more control over various options for compiling code.

- Use `[profile.*]` section

    ```toml
    [profile.dev]
    opt-level = 0

    [profile.release]
    opt-level = 3
    ```

### Publising a Crate to Crates.io

#### Making Useful Documentation Comments

- Documentation comments use three slashes, `///`, and support **Markdown** notation foor formatting the text.

```rust
/// Adds one to the number given
///
/// # Examples
/// ```
/// let arg = 5;
/// let answer = my_crate::add_one(arg);
///
/// assert_eq!(6, answer);
/// ```
pub fn add_one(x: i32) -> i32 {
    x + 1
}
```

- We can generate the HTML documentation from this documentation comment by running `cargo doc`.

- Here are some other sections that crate authors commonly use in thier documentation:

    - **Panics**: The scenarios in which the function being documented could panic.

    - **Errors**: If the function returns a `Result`, describing the kinds of errors that might occur and what conditions might cause those errors to be returned can be helpful.

    - **Safety**: If the function is `unsafe` to call, there should be a section explaining why the function is unsafe and covering the invariants that the function expects callers to uphold.

#### Documentation Comments as Tests

- Running `cargo test` will run the code examples in your documentations as tests.

#### Commenting Contained Items

- `//!` add documentation to the item that contains the comments

## Smart Pointers

- A *pointer* is a general concept for a variable that contains an addresss in memory.

- *Smart pointers* are data structures that not only act like a pointer but also have additional metadata and capabilities.

- The characteristic that distinguishes a smart pointer from an ordinary struct is that smart pointers implement the `Deref` and `Drop` traits.

    - The `Deref` trait allows an instance of the smart pointer sturct to behave like a reference.

    - The `Drop` trait allows you to customize the code that is run when an instance of the smart pointer goes out of scope.

- Most common smart pointers in the standard library:

    - `Box<T>` for allocating values on the heap
    - `Rc<T>`, a reference counting type that enables multiple ownership
    - `Ref<T>` and `RefMut<T>`, accessed through `RefCell<T>`, a type that enforces the borrowing rules at runtime instead of compile time

### Using `Box<T>` to Point to Data on the Heap

- You'll use them most often in these situations:

    - When you have a type whose size can't be known at compile time and you want to use a value of the type in a context that requires an exact size.

    - When you have a large amount of data and you want to transfer ownership but ensure the data won't be copied when you do so.

    - When you want to own a value and you care only that it's a type that implements a particular trait rather than being of a specific type.

#### Using a `Box<T>` to Store Data ont the Heap

```rust
fn main() {
    let b = Box::new(5);
    println("b = {}", b);
}
```

### Treating Smart Pointers Like Regular References with `Deref` Trait

- Implementing the `Deref` trait allows you to customsize the behavior of the *dereference operator*, `*`.

```rust
use std::ops::Deref;

struct MyBox<T>(T);

impl<T> MyBox<T> {
    fn new(x: T) -> MyBox<T> {
        MyBox(x)
    }
}

impl<T> Deref for MyBox<T> {
    type Target = T;

    fn deref(&self) -> &Self::Target {
        &self.0
    }
}
```

- Without the `Deref` trait, the compiler can only dereference `&` references. The `deref` method gives the compiler the ability to take a value of any type that implements `Deref` and call the `deref` method to get a `&` reference that it knows how to dereference.

    - When we entered `*y`, behind the scenes Rust actually ran this code: `*(y.deref())`

### Implicit Deref Coercions with Functions and Methods

- *Deref coercion* is a convenience that Rust performs on arguments to functions and methods.

- Deref coercion works only on types that implement the `Deref` trait.

### How Deref Coercion Interacts with Mutability

- Similiar to how you use the `Deref` trait to override the `*` operator on immutable references, you can use the `DerefMut` trait to override the `*` operator on mutable references.

- Rust does deref coercion when it find types and trait implementations in three cases:

    - From `&T` to `&U` when `T: Deref<Target=U>`
    - From `&mut T` to `&mut U` when `T: DerefMut<Target=U>`
    - From `&mut T` to `&U` when `T: Deref<Target=U>`

- Rust will also coerce a mutable reference to an immutable one, but the reverse is *not* possible.

### Running Code on Cleanup with the `Drop` Trait

- The `Drop` trait lets you customize what happens when a value is about to go out of scope.

```rust
struct CustomSmartPointer {
    data: String,
}

impl Drop for CustomSmartPointer {
    fn drop(&mut self) {
        println!("Dropping CustomSmartPointer with data `{}`!", self.data);
    }
}
```

### Dropping a Value Early with `std::mem::drop`

- If we need to force a value to be cleaned up early, we can use the `std::mem::drop` function.

```rust
fn main() {
    let c = CustomSmartPointer {
        data: String::from("some data"),
    };

    println("CustomSmartPointer created.");
    drop(c);
    println("CustomSmartPointer dropped before the end of main.");
}
```

### `Rc<T>`, the Reference Counted Smart Pointer

- To enable multiple ownership, Rust has a type called `Rc<T>`, which is an abbreviation for *reference counting*.

- Note that `Rc<T>` is only for use in single-threaded scenarios.

```rust
enum List {
    Cons(i32, Rc<List>),
    Nil,
}

use crate::List::{Cons, Nil};
use std::rc::Rc;

fn main() {
    let a = Rc::new(Cons(5, Rc::new(Cons(10, Rc::new(Nil)))));
    let b = Cons(3, Rc::clone(&a));
    let c = Cons(4, Rc::clone(&a));
}
```

### `RefCell<T>` and the Interior Mutability Pattern

- *Interior mutability* is a design pattern in Rust that allows you to mutate data even when there are immutable references to that data.

- Unlike `Rc<T>`, the `RefCell<T>` type represents single ownership over the data it holds.

- With references and `Box<T>`, the borrowing rules' invariants are enforced at compile time. With `RefCell<T>`, these invariants are enforced at *runtime*. With references, if you break these rules, you'll get a compiler error. With `RefCell<T>`, if you break these rules, your program will panic and exit.

- Differences with `Box<T>`, `Rc<T>` or `RefCell<T>`

    - `Rc<T>` enables multiple owners of the same data; `Box<T>` and `RefCell<T>` have single owners.

    - `Box<T>` allows immutable or mutable borrows checked at **compile time**; `Rc<T>` allows only immutable borrows checked at **compile time**; `RefCell<T>` allows immutable or mutable borrows checked at **runtime**.

    - Because `RefCell<T>` allows mutable borrows checked at runtime, you can mutate the value inside the `RefCell<T>` even when the `RefCell<T>` is immutable.


### Reference Cycles Can Leak Memory

- A simple example

    ```rust
    use crate::List::{Cons, Nil};
    use std::cell::RefCell;
    use std::rc::Rc;

    #[derive(Debug)]
    enum List {
        Cons(i32, RefCell<Rc<List>>),
        Nil,
    }

    impl List {
        fn tail(&self) -> Option<&RefCell<Rc<List>>> {
            match self {
                Cons(_, item) => Some(item),
                Nil => None,
            }
        }
    }

    fn main() {
        let a = Rc::new(Cons(5, RefCell::new(Rc::new(Nil))));

        println!("a initial rc count = {}", Rc::strong_count(&a));
        println!("a next item = {:?}", a.tail());

        let b = Rc::new(Cons(10, RefCell::new(Rc::clone(&a))));

        println!("a rc count after b creation = {}", Rc::strong_count(&a));
        println!("b initial rc count = {}", Rc::strong_count(&b));
        println!("b next item = {:?}", b.tail());

        if let Some(link) = a.tail() {
            *link.borrow_mut() = Rc::clone(&b);
        }

        println!("b rc count after changing a = {}", Rc::strong_count(&b));
        println!("a rc count after changing a = {}", Rc::strong_count(&a));

        // Uncomment the next line to see that we have a cycle;
        // it will overflow the stack
        // println!("a next item = {:?}", a.tail());
    }
    ```

- Turning an `Rc<T>` into a `Weak<T>` to prevent reference cycles

## Fearless Concurrency

### Using Threads to Run Code Simultaneously

- Some possible problems:

    - Race conditions, where threads are accessing data or resources in an inconsistent order.
    - Deadlocks, where two threads are waiting for each other to finish using a resource the order thread has, preventing both threads from continuing.
    - Bugs that happen only in certain situations and are hard to reproduce and fix reliably.

- Rust standard library only provides an implementation of 1:1 threading. Beacause Rust is such a low-level language, there are crates that implement M:N threading.

- Creating a new thread with `spawn`

    ```rust
    use std::thread;
    use std::time::Duration;

    fn main() {
        thread::spawn(|| {
            for i in 1..10 {
                println!("hi number {} from the spawned thread!", i);
                thread::sleep(Duration::from_millis(1));
            }
        });

        for i in 1..5 {
            println!("hi number {} from the main thread!", i);
            thread::sleep(Duration::from_millis(1));
        }
    }
    ```

- Waiting for all threads to finish using `join` handles

- Using `move` closures with Threads

    ```rust
    use std::thread;

    fn main() {
        let v = vec![1, 2, 3];

        let handle = thread::spawn(move || {
            println!("{:?}", v);
        });

        handle.join().unwrap();
    }
    ```

### Using Message Passing to Transfer Data Between Threads

- A *channel* in programming has two halves: a *transmitter* and a *receiver*.

- A *channel* is said to be *closed* if either the transmitter or receiver half is dropped.

- Creating multiple producers by `clone` the transmitter.

### Shared-State Concurrency

- Using mutexes to allow access to data from one thread at a time.

- *Mutex* is an abbreviation for *mutual exclusion*.

- `Arc<T>` is a type like `Rc<T>` that is safe to use in concurrent situations.

### Extensible Concurrency with the `Sync` and `Send` Traits

- Two concurrency concepts are embedded in the language: the `std::marker` traits `Sync` and `Send`.

- Allowing transference of ownership between threads with `Send`.

- Almost every Rust type is `Send`, but there are some exceptions, including `Rc<T>`.

- Any type composed entirely of `Send` types is automatically marked as `Send` as well, almost all primitive types are `Send`.

- Allowing access from multiple threads with `Sync`.

- Primitive types are `Sync`, and types composed entirely of types that are `Sync` are also `Sync`.

- Manually implementing these traits involves implementing unsafe Rust code.

## Object Oriented Programming Features of Rust

### Characteristics of Object-Oriented Languages

- Encapsulation that hides implementation details.

- Inheritance as a type system and as code sharing.

```rust
pub struct AveragedCollection {
    list: Vec<i32>,
    average: f64,
}

impl AveragedCollection {
    pub fn add(&mut self, value: i32) {
        self.list.push(value);
        self.update_average();
    }

    pub fn remove(&mut self) -> Option<i32> {
        let result = self.list.pop();
        match result {
            Some(value) => {
                self.update_average();
                Some(value)
            }
            None => None,
        }
    }

    pub fn average(&self) -> f64 {
        self.average
    }

    fn update_average(&mut self) {
        let total: i32 = self.list.iter().sum();
        self.average = total as f64 / self.list.len() as f64;
    }
}
```

### Using Trait Objects that allow for values of different types

- When we use trait objects, Rust must use **dynamic dispatch**. The compiler doesn't know all the types that might be used with the code that is using trait objects, so it doesn't know which method implemented on which type to call. Instead, at runtime, Rust uses the pointers inside the trait object to know which method to call.

- Dynamic dispatch also prevents the compiler from choosing to inline a method's code, which in turn prevents some optimizations.

- A trait is object safe if all the methods defined in the trait have the following properties:

    - The return type isn't `Self`.
    - There are no generic type parameters.

### Implementing an Object-Oriented Design Pattern

- Two pattern: see [blog](./../projects/blog) and [blog2](./../projects/blog2)

## Patterns and Matching

- A pattern consists of some combination of the following:

    - Literals
    - Destructured arrays, enums, structs, or tuples
    - Variables
    - Wildcards
    - Placeholders

### All the places patterns can be used

#### `match` arms

- One requirement for `match` expressions is that they need to be **exhaustive** in the sense that all possibilities for the value in the `match` expression must be accounted for.

- One way to ensure you've covered every possibility is to have a catchall pattern for the last arm.

- A particular pattern `_` will match anything, but it never binds to a variable.

#### Conditional `if let` expressions

- Using `if let` expressions is that compiler doesn't check exhaustiveness, whereas with `match` expressions it dose.

```rust
fn main() {
    let favorite_color: Option<&str> = None;
    let is_tuesday = false;
    let age: Result<u8, _> = "34".parse();

    if let Some(color) = favorite_color {
        println!("Using your favorite color, {}, as the background", color);
    } else if is_tuesday {
        println!("Tuesday is green day!");
    } else if let Ok(age) = age { // introduces a new shadowed age variable
        if age > 30 {
            println!("Using purple as the background color");
        } else {
            println!("Using orange as the background color");
        }
    } else {
        println!("Using blue as the background color");
    }
}
```

#### `while let` conditional loops

```rust
fn main() {
    let mut stack = Vec::new();

    stack.push(1);
    stack.push(2);
    stack.push(3);

    while let Some(top) = stack.pop() {
        println!("{}", top);
    }
}
```

#### `for` loops

- In a `for` loop , the pattern is the value that directly follows the keyword `for`, so in `for x in y` the `x` is the pattern.

```rust
fn main() {
    let v = vec!['a', 'b', 'c'];

    for (index, value) in v.iter().enumerate() {
        println!("{} is at index {}", value, index);
    }
}
```

#### `let` statements

- A `let` statement looks like this:

    ```rust
    let PATTERN = EXPRESSION;
    ```

#### Function parameters

```rust
fn print_coordinates(&(x, y): &(i32, i32)) {
    println!("Current location: ({}, {})", x, y);
}

fn main() {
    let point = (3, 5);
    print_coordinates(&point);
}
```

### Refutability: Whether a pattern migth fall to match

- Patterns come in two forms: refutable and irrefutable. Patterns that will match for any possible value passed are **irrefutable**.

- Function parameters, `let` statements, and `for` loops can only accept irrefutable patterns.

- The `if let` and `while let` expressions accept refutable and irrefutable patterns.

- `match` arms must use refutable patterns.

### Pattern Syntax

#### Matching Literals

```rust
let x = 1;

match x {
    1 => println!("one"),
    2 => println!("two"),
    3 => println!("three"),
    _ => println!("anything"),
}
```

#### Matching Named Variables

```rust
let x = Some(5);
let y = 10;

match x {
    Some(50) => println!("Got 50"),
    Some(y) => println!("Matched, y = {:?}", y),
    _ => println!("Default case, x = {:?}", x),
}

println!("at the end: x = {:?}, y = {:?}", x, y);
```

#### Multiple Patterns

```rust
let x = 1;

match x {
    1 | 2 => println!("one or two"),
    3 => println!("three"),
    _ => println!("anything"),
}
```

#### Matching Ranges of Values with `..=`

```rust
let x = 5;

match x {
    1..=5 => println!("one through five"),
    _ => println!("something else"),
}
```

- Ranges are only allowed with numberic values or `char` values.

```rust
let x = 'c';

match x {
    'a'..='j' => println!("early ASCII letter"),
    'k'..='z' => println!("late ASCII letter"),
    _ => println!("something else"),
}
```

#### Destructuring to Break Apart Values

- Destructuring Structs

    ```rust
    struct Point {
        x: i32,
        y: i32,
    }

    fn main() {
        let p = Point { x: 0, y: 7 };

        let Point { x: a, y: b } = p;
        let Point { x, y } = p;


        match p {
            Point { x, y: 0 } => println!("On the x axis at {}", x),
            Point { x: 0, y } => println!("On the y axis at {}", y),
            Point { x, y } => println!("On neither axis: ({}, {})", x, y),
        }
    }
    ```

- Destructuring Enums

    ```rust
    enum Message {
        Quit,
        Move { x: i32, y: i32 },
        Write(String),
        ChangeColor(i32, i32, i32),
    }

    fn main() {
        let msg = Message::ChangeColor(0, 160, 255);

        match msg {
            Message::Quit => {
                println!("The Quit variant has no data to destructure.")
            }
            Message::Move { x, y } => {
                println!(
                    "Move in the x direction {} and in the y direction {}",
                    x, y
                );
            }
            Message::Write(text) => println!("Text message: {}", text),
            Message::ChangeColor(r, g, b) => println!(
                "Change the color to red {}, green {}, and blue {}",
                r, g, b
            ),
        }
    }
    ```

- Destructuring Nested Structs and Enums

    ```rust
    enum Color {
        Rgb(i32, i32, i32),
        Hsv(i32, i32, i32),
    }

    enum Message {
        Quit,
        Move { x: i32, y: i32 },
        Write(String),
        ChangeColor(Color),
    }

    fn main() {
        let msg = Message::ChangeColor(Color::Hsv(0, 160, 255));

        match msg {
            Message::ChangeColor(Color::Rgb(r, g, b)) => println!(
                "Change the color to red {}, green {}, and blue {}",
                r, g, b
            ),
            Message::ChangeColor(Color::Hsv(h, s, v)) => println!(
                "Change the color to hue {}, saturation {}, and value {}",
                h, s, v
            ),
            _ => (),
        }
    }
    ```

- Destructuring Structs and Tuples

    ```rust
    let ((feet, inches), Point { x, y }) = ((3, 10), Point { x: 3, y: -10 });
    ```


#### Ignoring Values in a Pattern

- Ignoring an entire value with `_`

    ```rust
    fn foo(_: i32, y: i32) {
        println!("This code only uses the y parameter: {}", y);
    }
    ```

- Ignoring parts of a value with a nested `_`

    ```rust
    let mut setting_value = Some(5);
    let new_setting_value = Some(10);

    match (setting_value, new_setting_value) {
        (Some(_), Some(_)) => {
            println!("Can't overwrite an existing customized value");
        }
        _ => {
            setting_value = new_setting_value;
        }
    }
    ```

- Ignoring an unused variable by starting its name with `_`

    ```rust
    let _x = 5;
    let y = 10;
    ```

- Ignoring remaining parts of a value with `..`

    ```rust
    struct Point {
        x: i32,
        y: i32,
        z: i32,
    }

    let origin = Point { x: 0, y: 0, z: 0 };

    match origin {
        Point { x, .. } => println!("x is {}", x),
    }
    ```

#### Extra Conditionals with Match Guards

- A **match guard** is an additional `if` condition specified after the pattern in a `match` arm that must also match.

```rust
match num {
    Some(x) if x < 5 => println!("less than five: {}", x),
    Some(x) => println!("{}", x),
    None => (),
}
```

#### `@Bindings`

- The *at* operator (`@`) lets us create a variable that holds a value at the same time we’re testing that value to see whether it matches a pattern.

```rust
enum Message {
    Hello { id: i32 },
}

let msg = Message::Hello { id: 5 };

match msg {
    Message::Hello {
        id: id_variable @ 3..=7,
    } => println!("Found an id in range: {}", id_variable),
    Message::Hello { id: 10..=12 } => {
        println!("Found an id in another range")
    }
    Message::Hello { id } => println!("Found some other id: {}", id),
}
```

## Advanced Features

- Unsafe Rust: how to opt out of some of Rust's guarantees and take responsibility for manually upholding those guarantees.

- Advanced traits: associated types, default tye parameters, fully qualified syntax, supertraits, and the newtype pattern in relation to traits

- Advanced types: more about the newtype pattern, type aliases, the never type, and dynamicaly sized types

- Advanced functions and closures: function pointers and returning closures

- Macros: ways to define code that defines more code at compile time

### Unsafe Rust

- To switch to unsafe Rust, use the `unsafe` keyword and then start a new block that holds the unsafe code. you can:

    - Dereference a raw pointer
    - Call an unsafe function or method
    - Access or modify a mutable static variable
    - Implement an unsafe trait
    - Access fileds of `union`S

- It's important to understand that `unsafe` **doesn't** turn off the borrow checker or disable any other of Rust's safety checks: if you use a reference in unsafe code, it will still be checked. The `unsafe` keyword only gives you access to these five features that are then not checked by the compiler for memory safety.

#### Dereferencing a raw pointer

-  Unsafe Rust has two new types called **raw pointers** that re similar to references, `*const T` and `*mut T`.

- Different from references and smart pointers, raw pointers:

    - Are allowed to ignore the borrowing rules by having both immutable and mutable pointers or multiple mutable pointers to the same location
    - Aren't guaranteed to point to valid memory
    - Are allowed to be null
    - Don't implement any automatic cleanup

- We can create raw pointers in safe code, but we can't **dereference** raw pointers and read the data being pointed to.

```rust
let mut num = 5;

let r1 = &num as *const i32;
let r2 = &mut num as *mut i32;

unsafe {
    println!("r1 is: {}", *r1);
    println!("r2 is: {}", *r2);
}
```

#### Calling an unsafe function or method

- Unsafe functions and methods look exactly like regular functions and methods, but they have an extra `unsafe` before the rest of the definition.

- Bodies of unsafe functions are effectively `unsafe` blocks, so to perform other unsafe operations within an unsafe function, we don't need to add another `unsafe` block.

```rust
unsafe fn dangerous() {}

unsafe {
    dangerous();
}
```

#### Creating a safe abstraction over unsafe code

- A function contains unsafe code doesn't mean we need to mark the entire function as unsafe.

#### Using `extern` functions to call external code

```rust
extern "C" {
    fn abs(input: i32) -> i32;
}

fn main() {
    unsafe {
        println!("Absolute value of -3 according to C: {}", abs(-3));
    }
}
```

#### Accessing or modifying a mutable static variable

- In Rust, global variables are called **static variables**.

```rust
static HELLO_WORLD: &str = "Hello, world!";

fn main() {
    println!("name is: {}", HELLO_WORLD);
}
```

- Differences between constants and static variables:

    - Values in a static variable have a fixed address in memory. Using the value will always access the same data. Constants, on the other hand, are allowed to duplicate their data whenever they’re used.
    - Static variables can be mutable. Accessing and modifying mutable static variables is **unsafe**.

```rust
static mut COUNTER: u32 = 0;

fn add_to_count(inc: u32) {
    unsafe {
        COUNTER += inc;
    }
}

fn main() {
    add_to_count(3);

    unsafe {
        println!("COUNTER: {}", COUNTER);
    }
}
```

#### Implementing an unsafe trait

- A trait is unsafe when at least one of its methods has some invariant that the compiler can't verify.

```rust
unsafe trait Foo {
    // methods go here
}

unsafe impl Foo for i32 {
    // method implementations go here
}
```

#### Accessing fields of a union

- A `union` is similar to a `struct`, but only one declared filed is used in a particular instance at one time. Accessing union fields is unsafe because Rust can't guarantee the type of the data currently being stored in the union instance.

### Advanced Traits

#### Specifying placeholder types in trait definition with associated types

- **Associated types** connect a type placeholder with a trait such that the trait method definitions can use these placeholder types in their signatures.

```rust
pub trait Iterator {
    type Item;
    
    fn next(&mut self) -> Option<Self::Item>;
}
```

#### Default generic type parameters and operator overloading

- Rust doesn't allow you to create your own operators or overload arbitrary operators. But you can overload the operations and corresponding traits listed in `std::ops` by implementing the traits associated with the operator.

- You'll use default type parameters in two main ways:

    - To extend a type without breaking existing code.
    - To allow customization in specific cases most users won't need.

```rust
use std::ops::Add;

#[derive(Debug, Copy, Clone, PartialEq)]
struct Point {
    x: i32,
    y: i32,
}

impl Add for Point {
    type Output = Point;

    fn add(self, other: Point) -> Point {
        Point {
            x: self.x + other.x,
            y: self.y + other.y,
        }
    }
}

fn main() {
    assert_eq!(
        Point { x: 1, y: 0 } + Point { x: 2, y: 3 },
        Point { x: 3, y: 3 }
    );
}
```

#### Fully qualified syntax for disambiguation: call methods with the same name

- Fully qualified syntax is defined as follows:

    ```rust
    <Type as Trait>::function(receiver_if_method, next_arg, ...)
    ```
    
```rust
trait Pilot {
    fn fly(&self);
}

trait Wizard {
    fn fly(&self);
}

struct Human;

impl Pilot for Human {
    fn fly(&self) {
        println!("This is your captain speaking.");
    }
}

impl Wizard for Human {
    fn fly(&self) {
        println!("Up!");
    }
}

impl Human {
    fn fly(&self) {
        println!("*waving arms furiously*");
    }
}

fn main() {
    let person = Human;
    Pilot::fly(&person);
    Wizard::fly(&person);
    person.fly();
}
```

```rust
trait Animal {
    fn baby_name() -> String;
}

struct Dog;

impl Dog {
    fn baby_name() -> String {
        String::from("Spot")
    }
}

impl Animal for Dog {
    fn baby_name() -> String {
        String::from("puppy")
    }
}

fn main() {
    println!("A baby dog is called a {}", <Dog as Animal>::baby_name());
}
```

#### Using supertraits to require one trait's functionality within another trait

- The trait you rely on is a **supertrait** of the trait you're implementing.

```rust
use std::fmt;

trait OutlinePrint: fmt::Display {
    fn outline_print(&self) {
        let output = self.to_string();
        let len = output.len();
        println!("{}", "*".repeat(len + 4));
        println!("*{}*", " ".repeat(len + 2));
        println!("* {} *", output);
        println!("*{}*", " ".repeat(len + 2));
        println!("{}", "*".repeat(len + 4));
    }
}
```

#### Using the newtype pattern to implement external traits on external types

- Newtype pattern: involving creating a new type in a tuple struct.

- If we wanted the new type to have every method the inner type has, implementing the `Deref` trait on the wrapper type to return the inner type would be a solution. If we don't want the wrapper type to have all the methods of the inner type, we would have to implement just the methods we do want manually.

```rust
use std::fmt;

struct Wrapper(Vec<String>);

impl fmt::Display for Wrapper {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "[{}]", self.0.join(", "))
    }
}
```

### Advanced Types

#### Creating Type Synonyms with Type Aliases

- Rust provides the ability to declare a **type alias** to give an existing type another name.

```rust
type Kilometers = i32;

type Thunk = Box<dyn Fn() + Send + 'static>;

type Result<T> = std::result::Result<T, std::io::Error>;
```

#### The Never Type that Never Returns

- Rust has a special type named `!` that's known in type theory lingo as the *empty type* because it has no values.

- Functions that return never are called *divergin functions*.

```rust
fn bar() -> ! {
    // --snip--
}
```

#### Dynamically Sized Types and the Sized Trait

- Dynamically sized types: sometimes referred to as DSTs or unsized types, these types let us write code using values whoes size we can know only at runtime.

- Every trait is a dynamically sized type we can refer to by using the name of the trait.

- To work with DSTs, Rust has a particular trait called the `Sized` trait to determine whether or not a type's size is known at compile time.

### Advanced Functions and Closures

#### Function Pointers

- Functions coerce to the type `fn`, not to be confused with the `Fn` closure trait. The `fn` type is called a *function pointer*.

```rust
fn add_one(x: i32) -> i32 {
    x + 1
}

fn do_twice(f: fn(i32) -> i32, arg: i32) -> i32 {
    f(arg) + f(arg)
}
```

- Function pointers implement all three of the closure traits(`Fn`, `FnMut`, and `FnOnce`), so you can always pass a function pointer as an argument for a function that expects a closure.

#### Returning Closures

```rust
fn returns_closure() -> Box<dyn Fn(i32) -> i32> {
    Box::new(|x| x + 1)
}
```

### Macros

- The term *macro* refers to a family of features in Rust: *declarative* macros with `macro_rules!` annd three kinds of *procedural* macros:

    - Custom `#[derive]` macros that specify code added with the `derive` attribute used on structs and enums
    - Attribute-like macros that define custom attributes usable on any item
    - Function-like macros that look like function calls but operate on the tokens specified as thier argument

#### The difference between macros and functions

- Macros are a way of writing code that writes other code, which is known as *metaprogramming*.

- You must define macros or bring them into scope *before* you call them in a file, as opposed to functions you can define anywhere and call anywhere.

#### Delcarative macros with `macro_rules!` for general metaprogramming

- Start the macro definition with `macro_rules!` and the name of macro we're defining **without** the exclamation mark(`!`).

```rust
#[macro_export]
macro_rules! vec {
    ( $( $x:expr ),* ) => {
        {
            let mut temp_vec = Vec::new();
            $(
                temp_vec.push($x);
            )*
            temp_vec
        }
    };
}
```

#### Procedural macros for generating code from attributes

- Procedural macros accept some code as an input, operate on that code, and produce some code as an output rather than matching against patterns and replacing the mode with other code as declarative macros do.

```rust
use proc_macro;

#[some_attribute]
pub fn some_name(input: TokenStream) -> TokenStream {
}
```

- Write a custom `derive` macro, see [hello_macro](../projects/hello_macro) and [hello_macro_derive](../projects/hello_macro_derive)

- Attribute-like macros

    ```rust
    #[route(GET, "/")]
    fn index() {

    ...

    #[proc_macro_attribute]
    pub fn route(attr: TokenStream, item: TokenStream) -> TokenStream {
    ```

- Function-like macros

    ```rust
    let sql = sql!(SELECT * FROM posts WHERE id=1);

    ...

    #[proc_macro]
    pub fn sql(input: TokenStream) -> TokenStream {
    ```
