class Solution {

public:

  int trap(vector<int>& h) {
      int maxpos = 0; // предполагаем, что высота первого элемента максимальна, и устанавливаем его индекс 0 в переменную maxpos
  
      // поиск первого вхождения максимума
      for (int i = 0; i < h.size(); ++i) { // пробегаем по индексам всех элементов (блоков)
          if (h[i] > h[maxpos]) { // если значение текущего элемента больше (>) значения элемента с индексом maxpos (0-индекс первого оборота):
              maxpos = i; // перезаписываем индекс максимального элемента и устанавливаем индекс текущего элемента
          }
      }

      // проходим слева направо до максимума, так как справа максимум можем гарантировать, что вода справа не будет выливаться, поэтому только слева может быть протечка, если слева есть ограничение, то протечки не будет
      int ans = 0; // устанавливаем значение (0) для новой переменной ответа (здесь мы собираем блоки воды)
      int nowm = 0; // устанавливаем значение (0) - для новой переменной nowm (новый максимум)
      for (int i = 0; i < maxpos; ++i) { // пробегаем по индексам всех элементов слева до нашего maxpos (индекс максимального элемента)
          if (h[i] > nowm) { // если значение текущего элемента больше (>) значения элемента nowm (0 - первый оборот):
              nowm = h[i]; // устанавливаем значение текущего элемента переменной nowm
          }
          ans += nowm - h[i]; // добавляем к общему значению блоков воды (переменной ans) разницу между nowm (новым максимумом) и текущим элементом
      }
  
      nowm = 0; // снова устанавливаем значение (0) - для новой переменной nowm (новый максимум)
      for (int i = h.size() - 1; i > maxpos; --i) { // пробегаем по индексам всех элементов справа до нашего maxpos (индекс максимального элемента)
          if (h[i] > nowm) { // если значение текущего элемента больше (>) значения элемента nowm (0 - первый оборот):
              nowm = h[i]; // устанавливаем значение текущего элемента переменной nowm
          }
          ans += nowm - h[i]; // добавляем к общему значению блоков воды (переменной ans) разницу между nowm (новым максимумом) и текущим элементом
      }
  
      return ans; // возвращаем значение общего количества блоков воды
  }


};
/*
class Solution {
public:
    int trap(vector<int>& height) {
        
        int IdxTotalMax;
        int TotalMax = -1;
        for(int i = 0; i < height.size(); ++i){
            if(TotalMax < height[i]){
                IdxTotalMax = i;
                TotalMax = height[i];
            }
        }


        int Ans = 0;
        int IdxLocalMax = 0;
        for(int i = 0; i < IdxTotalMax; ++i){
            
            if(height[IdxLocalMax] > height[i]){
                // количество заполненной воды равно перепаду высот текущего уровня высоты и максимального слева (справа не сможет вылиться так как глобальный максимум)
                Ans += (height[IdxLocalMax] - height[i]); 
            }else{
                IdxLocalMax = i;
            }
            
        }

        IdxLocalMax = height.size() - 1;
        for(int i = height.size() - 1; i > IdxTotalMax;--i){
            if(height[IdxLocalMax] > height[i]){
                // количество заполненной воды равно перепаду высот текущего уровня высоты и максимального справа (слева не сможет вылиться так как глобальный максимум)
                Ans += (height[IdxLocalMax] - height[i]); 
            }else{
                IdxLocalMax = i;
            }
        }


        return Ans;

    }
};
*/
