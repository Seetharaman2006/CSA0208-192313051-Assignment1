# TASK 1: UNDERSTAND THE PROBLEM AND IDENTIFY THE DATA

## 1. Problem Description

Grama Jyothi is a rural electricity co-operative that provides electricity to approximately 4,000 households. The billing program must calculate electricity consumption from previous and current meter readings and generate accurate bills based on fixed charges and slab-based tariffs.

The program must handle meter rollover, prevent incorrect bills, and support tariff revisions.

## 2. Inputs and Outputs

### Inputs

* Previous meter reading.
* Current meter reading.
* Household or meter identification number.
* Consumer category, if different tariffs apply to different categories.

### Outputs

* Electricity units consumed.
* Energy charge.
* Fixed charge.
* Total electricity bill.
* Error message if the input readings are invalid.

## 3. Constants

| Constant                              |          Value |
| ------------------------------------- | -------------: |
| First slab limit                      |      100 units |
| Second slab limit                     |      200 units |
| Rate for first 100 units              |    ₹0 per unit |
| Rate for units 101–200                | ₹2.25 per unit |
| Rate above 200 units                  | ₹4.50 per unit |
| Fixed charge                          |            ₹50 |
| Maximum 16-bit unsigned meter reading |          65535 |

Constants allow tariff changes to be made in one place without modifying every calculation.

## 4. Selection of Data Types

| Data item              | C data type          | Reason                                                                      |
| ---------------------- | -------------------- | --------------------------------------------------------------------------- |
| Previous meter reading | `unsigned short`     | Stores non-negative meter readings on systems where its range is sufficient |
| Current meter reading  | `unsigned short`     | Stores the latest meter reading                                             |
| Units consumed         | `unsigned int`       | Represents non-negative consumption                                         |
| Household ID           | `char[]`             | Stores an identifier as text                                                |
| Bill amount            | `long`               | Stores monetary values in integer paise                                     |
| Tariff values          | `#define` or `const` | Defines reusable tariff constants                                           |
| Loop counter           | `int`                | Counts iterations                                                           |

**Note:** C does not guarantee that `unsigned short` is exactly 16 bits. The program should verify the type's size and maximum value on the target system.

## 5. Negative, Fractional, and Large Values

* Meter readings must not be negative.
* Electricity consumption must not be negative after rollover handling.
* Tariff rates may represent fractional rupee amounts, such as ₹2.25.
* Store money as integer paise to avoid floating-point representation errors.
* Total charges across many households can become large, so a suitable integer type and overflow checks are required.

For example, ₹2.25 can be represented as 225 paise.

## 6. Rules for a Correct Bill

1. Calculate consumption using the previous and current meter readings.
2. Handle a valid meter rollover without producing negative consumption.
3. Reject invalid meter readings.
4. The first 100 units are free.
5. Units 101–200 cost ₹2.25 per unit.
6. Units above 200 cost ₹4.50 per unit.
7. Add the fixed charge of ₹50.
8. The total bill must equal the energy charge plus the fixed charge.
9. The bill must not be negative.

## 7. Assumptions

* The first 100 units are free.
* The fixed charge is ₹50 per billing period.
* The meter uses a 16-bit unsigned register with a maximum reading of 65535.
* At most one rollover occurs between consecutive readings.
* The specified tariff remains unchanged during one billing calculation.

If multiple rollovers can occur between readings, timestamps or additional meter information will be necessary.

## 8. Alternative Concept: Store Meter Readings as Text

Meter readings could be stored as character strings, such as `"01530"`, instead of numeric values.

The program would need to validate the digits and convert the text into a number before calculating consumption.

If a reading contains `d` digits:

* Text conversion takes O(d) time.
* Text storage requires O(d) space.
* Arithmetic using a fixed-width numeric type takes O(1) time and O(1) space.

Text storage preserves leading zeros, but numeric storage is more convenient for calculations.

## 9. Time and Space Complexity

For one household, calculating consumption and the bill requires a fixed number of operations.

* Time complexity per household: O(1).
* Auxiliary space per household: O(1).
* Processing `n` househ
