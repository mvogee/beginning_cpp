int FindOutlier(std::vector<int> arr)
{
    int result;
    int even_count = 0;
    int odd_count = 0;
    int first_odd;
    int first_even;

    for (ulong i = 0; i < arr.size(); i++) {
      if (arr[i] % 2 == 0) {
        even_count++;
        first_even = arr[i];
      }
      else {
        odd_count++;
        first_odd = arr[i];
      }
      if (i > 2 && even_count > 0 && odd_count > 0) {
        if (odd_count > even_count)
          result = first_even;
        else
          result = first_odd;
        break;
      }
    }
    return result;
}
