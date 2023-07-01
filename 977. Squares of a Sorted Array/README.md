Будем заполнять искомый вектор справа налева, кладя max(nums[LeftBorderWindow] * nums[LeftBorderWindow], nums[RightBorderWindow ] * nums[RightBorderWindow]) 
в nums[i] и сдвигая границу окна в зависимости от того, 

При этом не забываем после каждой вставки сдвигать i влево, то есть вычитать 1. 
