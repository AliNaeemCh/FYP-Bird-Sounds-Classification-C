short mode(short *data, short length) {
   short maxValue = 0, maxCount = 0;

   for (i = 0; i < length; ++i) {
      short count = 0;
      
      for (j = 0; j < length; ++j) {
         if (data[j] == data[i])
         ++count;
      }
      
      if (count > maxCount) {
         maxCount = count;
         maxValue = data[i];
      }
   }

   return maxValue;
}