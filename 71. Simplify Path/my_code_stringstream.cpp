class Solution {
public:
    string simplifyPath(string& path) { // error with string_view
        
        // RE on "6 / 258 testcases passed" without "path.empty() == false &&" on ex: "/"
        while(path.empty() == false && (path.back() == '/' /*|| path.back() == '.'*/)){ // Если вы столкнетесь с символом "/", то игнорируйте его.
            /* ошибка при использовании || path.back() == '.'
            Wrong Answer 210 / 258 testcases passed   
            Input path = "/a//b////c/d//././/.." == "/a/b/c/d/././.." 
            Output "/a/b/c/d" 
            Expected "/a/b/c"
            */
            path.pop_back();
            }

        stringstream PartPath(path);

        string CanonicalPath; // further: CP

        vector<string> PartsCP; PartsCP.reserve(1 + path.size()/2);

        // Как getline отреагирует на PartPath = ...///...?
        // Ответ: в buffer будет записыываться пустая строка, для этого и нужна проверка "buffer.empty()"
        for(string buffer; getline(PartPath, buffer, '/');){


            // Какая будет ошиба при закоменченном "buffer.empty()"???
            // Ответ: в PartsCP будет класться пустая строка из buffer --> избыточное количетсво "/" в CanonicalPath
            if(buffer.empty() || buffer == "."){continue;}

            // Какая будет ошиба при закоменченном "PartsCP.empty() == false &&"???
            // Ответ: RE на Example 4: Input: path = "/../" Output: "/"
            if(PartsCP.empty() == false && buffer == ".."){

                PartsCP.pop_back();
                continue;
            }
            
            // Example 2:
            if(buffer != ".."){ // в buffer может лежать либо directory, либо "..", при этом ".." там может нахоидтся по причине того, что PartsCP.empty() == true 
		    		// -- то есть нет директории, куда можно было бы вернутся и предыдущей условный оператор не отработал 
		    		// например, это можно заметить в тесте: Example 4: Input: path = "/../" Output: "/"
                PartsCP.push_back(buffer);
                }
            
        }

        PartsCP.shrink_to_fit();

        // Example 2:
        if(PartsCP.empty()){return "/";}

        for(const string& Part : PartsCP){
            CanonicalPath += "/" + Part;
        }

        return CanonicalPath;
    }
};

/* Пояснение к 33 строке: 
// ERROR!
#include <vector>

int main() {

	std::vector<int> foo;
	foo.pop_back(); // Expression: vector empty before pop

}
*/
