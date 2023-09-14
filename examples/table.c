#include <stdlib.h>

#include "ConsoleColor.h"

int main() {
  // Example table data
  const char* row1[] = {"Name", "Age", "City"};
  const char* row2[] = {"Alice", "25", "New York"};
  const char* row3[] = {"Bob", "30", "San Francisco"};
  const char* row4[] = {"Charlie", "22", "Los Angeles"};

  const char*** tableData = (const char***)malloc(4 * sizeof(const char**));
  tableData[0] = row1;
  tableData[1] = row2;
  tableData[2] = row3;
  tableData[3] = row4;

  int numRows = 4;
  int numCols = 3;

  // Print the table
  c_printTable(tableData, numRows, &numCols);

  // Free dynamically allocated memory
  free(tableData);

  return 0;
}
