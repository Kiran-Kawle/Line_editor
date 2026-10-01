# Simple C Line Editor

## Team Information
* **Team Members:**
  * [KIRAN] 
  * [MANOJ RATHOD]
  * [DASHRATH M]
* **Note:** Core logic implementation and testing were completed individually during the studio competition as teammates were assigned to other course activities.

## Implemented Features
* **Insert Line:** Adds text at a specified line index and shifts subsequent lines down.
* **Delete Line:** Removes text at a specified line index and shifts subsequent lines up.
* **Display Document:** Shows all lines in order with their corresponding line numbers.

## Data Structure Choice & Justification
* **Data Structure:** Fixed-size 2D Character Array (`char doc[100][256]`)
* **Justification:** Contiguous memory layout provides O(1) index access and simple string operations using standard C library functions (`strcpy`, `strncpy`), avoiding memory allocation complexity under tight time limits.

## How to Compile and Run
1. Open terminal in the project folder.
2. Compile using GCC:
   ```bash
   gcc main.c -o line_editor
