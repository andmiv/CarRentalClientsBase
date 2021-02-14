#include <QGuiApplication>
#include <QQmlApplicationEngine>
/*
 * Предметная область: Обслуживание клиентов в бюро проката автомобилей (см. п. 9.2)
 * 9.2.1. Информационная система для предметной области «Обслуживание клиентов в бюро проката автомобилей» должна осуществлять ввод, хранение, обработку и вывод данных о:
 * – клиентах;
 * – автомобилях, принадлежащих бюро проката;
 * – выдаче на прокат и возврате автомобилей от клиентов.
 * 9.2.2. Данные о каждом клиенте должны содержать:
 * – Номер водительского удостоверения – строка формата «RR AA NNNNNN»,
 * где RR – код региона (цифры); AA – серия (буквы из следующего множества: А, В, Е, К, М, Н, О, Р, С, Т, У, Х); NNNNNN –
 * порядковый номер удостоверения (цифры). Код, серия и номер отделяются друг от друга пробелами;
 * – ФИО – строка;
 * – Паспортные данные – строка;
 * – Адрес – строка.
 * Примечание: длина строк (кроме номер водительского удостоверения) определяется студентом самостоятельно.
 * 9.2.3. Данные о клиентах должны быть организованны в виде
 * АВЛ-дерева поиска, упорядоченного по «номеру водительского удостоверения».
 * 9.2.4. Данные о каждом автомобиле должны содержать:
 * – Государственный регистрационный номер – строка формата
 * «ANNNAA-NN», где N –цифра; A – буква из следующего множества:
 * А, В, Е, К, М, Н, О, Р, С, Т, У, Х;
 * – Марку – строка;
 * – Цвет – строка;
 * – Год выпуска – целое;
 * – Признак наличия – логическое.
 * Примечание: длина строк (кроме «Государственного регистрационного номера») определяется студентом самостоятельно.
 * 9.2.5. Данные об автомобилях должны быть организованны в виде хеш-таблицы, первичным ключом которой является «Государственный регистрационный номер». Метод хеширования определяется вариантом задания.
 * 9.2.6. Данные о выдаче на прокат или возврате автомобилей от
 * клиентов должны содержать:
 * – строку, формат которой соответствует аналогичной строке
 * в данных о клиентах;
 * Метод хеширования: Закрытое хеширование с линейным опробованием
 * Метод сортировк: Быстрая (Хоара)
 * Вид списка: Линейный двунаправленный
 * Метод обхода дерева: Метод обхода дерева
 * Алгоритм поиска слова в тексте: Метод обхода дерева
 */

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
