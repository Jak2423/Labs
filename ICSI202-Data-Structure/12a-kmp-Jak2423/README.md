[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10946158&assignment_repo_type=AssignmentRepo)
# KMP алгоритм хэрэгжүүлэх
![GitHub Classroom Workflow](../../workflows/GitHub%20Classroom%20Workflow/badge.svg?branch=main) ![Points badge](../../blob/badges/.github/badges/points.svg)

Линукс үйлдлийн системийн маш өргөн хэрэглэгддэг хүчирхэг хэрэгслүүдийн нэг нь `grep` команд юм. Уг команд текст файлаас үг хайх боломжийг олгодог. Энэхүү хэрэгсэлтэй төстэй `mygrep` командыг хэрэгжүүлнэ үү.
Таны команд нь дараах үйлдлүүдийг хийх боломжтой байх ёстой.

  * Үг хайх
    ```shell
    mygrep Mongolia SecretHistoryOfMongolia.txt
    ```
    команд нь `SecretHistoryOfMongolia.txt` нэртэй файлаас `Mongolia` гэдэг үгийг хайна. 

  * Том, жижиг үсгийг ялгахгүйгээр хайх
    ```shell
    mygrep -i mongolia SecretHistoryOfMongolia.txt
    ```
    команд нь `SecretHistoryOfMongolia.txt` нэртэй файлаас `mongolia` гэдэг үгийг том, жижиг үсэг гэж ялгалгүйгээр хайна. 
    
Таны програм 550,516 үгтэй, 4MB хэмжээтэй өгөгдөл дээр богино, урт үгийн бүх тохиолдлыг **4 секунтын дотор** олох ёстой.
## Даалгаврыг хийх заавар

Даалгаврыг KMP алгоритм ашиглан хэрэгжүүлнэ.

Хайлтыг хийх файлын нэр болон хайх хэвийг програмыг ажиллахдаа аргументаар зааж өгнө. Програмд дамжуулж өгсөн аргументууд `main` функцийн аргумент болон ирдэг. Жишээ нь программыг
```
mygrep -i mongolia SecretHistoryOfMongolia.txt
```
гэж дуудсан бол
```C
int main(int argc, char *argv[])
```
функцийн аргумент нь

| main функцийн аргументууд               |
|:----------------------------------------|
| argc = 4                                |
| argv[0] = "mygrep"                      |
| argv[1] = "-i"                          |
| argv[2] = "mongolia"                    |
| argv[3] = "SecretHistoryOfMongolia.txt" |

гэсэн утгууд хадгалдаг.

### Хэрэгжүүлэх функцүүд

  * `DFA` хүснэгт байгуулах функц: `pattern` хэвийг боловсруулан төгсгөлөгт төлөвт автоматын шилжилтийг `dfa`-д хадгална. `R` нийт байж болох тэмдэгтийн тоо буюу ASCII кодын хамгийн дээд хязгаар.
    ```C
    void KMP(const char *pattern, int *dfa[], int R);
    ```
    
  * Хайлт хийх функц: `pattern` хэвийг `buf` тестээс `index` байрлалаас эхлэн хайн хамгийн түрүүнд олдсон байрлалыг буцаана. Олдохгүй бол -1 утгыг буцаана. Хэрэв хайж буй хэв олдсон бол хэддүгээр мөрөнд олдсон бэ гэдгийг мэдэхийн тулд `pline`-д хадгалагдсан өгөгдлийг ашиглана. Хайлт хийж байхдаа дараагийн мөрөнд шилжсэн бол `(*pline)++` гэх ба энэ нь одоогийн мөрийн дугаарыг нэгээр нэмэгдүүлнэ.
  
    `dfa` нь `pattern` хэвд тохирсон `dfa` хүснэгт.
  
    Хэрэв `case_insensitive = 1` байвал том, жижиг үсгийг адил гэж үзнэ. Харин `0` байвал том, жижиг үсгүүд ялгаатай гэж үзнэ.
  
    ```C
    int find(const char *buf, int index, const char *pattern, int *dfa[], int *pline);
    ```
  
    **Уг функц дотор strlen() ашиглах нь програмыг удаашруулахыг анхаарна уу!** 