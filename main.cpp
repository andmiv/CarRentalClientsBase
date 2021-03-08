//#include "mainwindow.h"
#include "consoleapplication.h"

/*
 * Предметная область: Обслуживание клиентов в бюро проката автомобилей (см. п. 9.2)
 * 9.2.1. Информационная система для предметной области «Обслуживание клиентов в бюро проката автомобилей» должна осуществлять ввод, хранение, обработку и вывод данных о:
 * – клиентах;
 * – автомобилях, принадлежащих бюро проката;
 * – выдаче на прокат и возврате автомобилей от клиентов.
 *
 * 9.2.2. Данные о каждом клиенте должны содержать:
 * – Номер водительского удостоверения – строка формата «RR AA NNNNNN»,
 * где RR – код региона (цифры); AA – серия (буквы из следующего множества: А, В, Е, К, М, Н, О, Р, С, Т, У, Х); NNNNNN –
 * порядковый номер удостоверения (цифры). Код, серия и номер отделяются друг от друга пробелами;
 * – ФИО – строка;
 * – Паспортные данные – строка;
 * – Адрес – строка.
 * Примечание: длина строк (кроме номер водительского удостоверения) определяется студентом самостоятельно.
 *
 * 9.2.3. Данные о клиентах должны быть организованны в виде
 * АВЛ-дерева поиска, упорядоченного по «номеру водительского удостоверения».
 *
 * 9.2.4. Данные о каждом автомобиле должны содержать:
 * – Государственный регистрационный номер – строка формата
 * «ANNNAA-NN», где N –цифра; A – буква из следующего множества:
 * А, В, Е, К, М, Н, О, Р, С, Т, У, Х;
 * – Марку – строка;
 * – Цвет – строка;
 * – Год выпуска – целое;
 * – Признак наличия – логическое.
 * Примечание: длина строк (кроме «Государственного регистрационного номера») определяется студентом самостоятельно.
 *
 * 9.2.5. Данные об автомобилях должны быть организованны в виде хеш-таблицы, первичным ключом которой является
 * «Государственный регистрационный номер». Метод хеширования определяется вариантом задания.
 *
 * 9.2.6. Данные о выдаче на прокат или возврате автомобилей от
 * клиентов должны содержать:
 * – строку, формат которой соответствует аналогичной строке
 * в данных о клиентах;
 * – Государственный регистрационный номер – строка, формат которой соответствует аналогичной строке в данных об автомобилях;
 * – Дату выдачи – строка;
 * – Дату возврата – строка.
 * Примечание: наличие в этих данных записи, содержащей в поле
 * «Номер водительского удостоверения» значение X и в поле «Государственный регистрационный номер» значение Y,
 * означает выдачу клиенту с номером водительского удостоверения X автомобиля
 * с государственным регистрационным номером Y. Отсутствие такой
 * записи означает, что клиенту с номером водительского удостоверения X не выдавался автомобиль с номером Y.
 *
 * 9.2.7. Данные о выдаче на прокат или возврате автомобилей от
 * клиентов должны быть организованны в виде списка, который упорядочен по первичному ключу –
 * «Государственный регистрационный номер». Вид списка и метод сортировки определяются вариантом задания.
 *
 * 9.2.8. Информационная система «Обслуживание клиентов в бюро проката автомобилей» должна осуществлять следующие операции:
 * – регистрацию нового клиента;
 * – снятие с обслуживания клиента;
 * – просмотр всех зарегистрированных клиентов;
 * – очистку данных о клиентах;
 * – поиск клиента по «номер водительского удостоверения». Результаты поиска –
 * все сведения о найденном клиенте и государственный регистрационный номер автомобиля, который ему выдан;
 * – поиск клиента по фрагментам ФИО или адреса. Результаты поиска –
 * список найденных клиентов с указанием номера водительского удостоверения, ФИО и адреса;
 *
 * – добавление нового автомобиля;
 * – удаление сведений об автомобиле;
 * – просмотр всех имеющихся автомобилей;
 * – очистку данных об автомобилях;
 * – поиск автомобиля по «Государственному регистрационному
 * номеру». Результаты поиска – все сведения о найденном автомобиле,
 * а также ФИО и номер водительского удостоверения клиента, которому выдан этот автомобиль;
 * – поиск автомобиля по названию марки автомобиля. Результаты поиска –
 * список найденных автомобилей с указанием «Государственный регистрационный номер», марки, цвета, года выпуска;
 *
 * – регистрацию отправки автомобиля в ремонт;
 * – регистрацию прибытия автомобиля из ремонта;
 * – регистрацию выдачи клиенту автомобиля на прокат;
 * – регистрацию возврата автомобиля от клиентов.
 *
 * 9.2.9. Состав данных о клиенте или автомобиле, выдаваемых при
 * просмотре всех зарегистрированных клиентов или просмотре всех
 * автомобилей, принадлежащих бюро проката, определяется студентом самостоятельно, но должен содержать не менее двух полей.
 *
 * 9.2.10. Метод поиска автомобиля по марке определяется студентом самостоятельно.
 * Выбранный метод необходимо сравнить с альтернативными методами.
 *
 * 9.2.11. Поиск клиента по фрагментам ФИО или адреса должен
 * осуществляться путем систематического обхода АВЛ-дерева поиска.
 * Метод обхода определяется вариантом задания. При поиске клиента по фрагментам
 * ФИО или адреса могут быть заданы как полное
 * ФИО или адрес, так и их части (например, только фамилия клиента без имени и отчества, только название улицы из адреса).
 * Для обнаружения заданного фрагмента в полном ФИО или адресе должен
 * применяться алгоритм поиска слова в тексте, указанный в варианте задания.
 *
 * 9.2.12. Регистрация отправки автомобиля на ремонт должна
 * осуществляться только при наличии этого автомобиля (значение
 * поля «Признак наличия» для соответствующего автомобиля имеет значение «Истина»).
 * При этом значение поля «Признак наличия» для соответствующего автомобиля изменяется на значение «Ложь».
 *
 * 9.2.13. При регистрации прибытия автомобиля из ремонта значение поля «Признак наличия» для соответствующего автомобиля
 * изменяется на значение «Истина».
 *
 * 9.2.14. Регистрация выдачи автомобиля клиенту должна осуществляться только при наличии свободного
 * выдаваемого автомобили (значение поля «Признак наличия» для соответствующего автомобиля имеет значение «Истина»).
 *
 * 9.2.15. При регистрации выдачи автомобиля клиенту или возврата автомобиля от клиента должно корректироваться значение
 * поля «Признак наличия» для соответствующего автомобиля.
 *
 * 9.2.16. При снятии с обслуживания клиента должны быть учтены и обработаны ситуации, когда у клиента имеется выданный
 * автомобиль. Аналогичным образом следует поступать и с удалением сведений об автомобилях.
 *
 * Метод хеширования: Закрытое хеширование с линейным опробованием
 * Метод сортировк: Быстрая (Хоара)
 * Вид списка: Линейный двунаправленный
 * Метод обхода дерева: Обратный
 * Алгоритм поиска слова в тексте: Прямой
 */

const char *carsFile = "/home/mranderson/Education/CarRentalClientsBase/cars.txt";
const char *clientsFile = "/home/mranderson/Education/CarRentalClientsBase/clients.txt";
const char *rentFile = "/home/mranderson/Education/CarRentalClientsBase/rentinfo.txt";

int main(int, char **)
{    
    ConsoleApplication app;
    app.load(carsFile, clientsFile, rentFile);
    app.exec();
    return 0;
}
