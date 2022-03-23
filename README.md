# Лаба 2 - Использование внешних библиотек.
На основании данных с сайта ЦБ РФ написать программу, которая раз в 10 секунд
опрашивает данные о курсе валют и выводит текущие значения.
По окончанию работы выводит среднее и медианное значение.
В рамках работы Вам понадобятся:

1. Данные от ЦБ. Публичное [API](https://www.cbr-xml-daily.ru/#howto)
2. Способ им воспользоваться из С++. Можно выбрать любую библиотеку,
например [libcurl](https://curl.se/libcurl/)
3. Библиотека для работы с JSON. Можно выбрать любую, например
[JSON](https://github.com/nlohmann/json)

Для хранения и подсчета статистики, спроектировать и реализовать структуры данных,
обеспечивающие оптимальную алгоритмическую сложность расчетов и не избыточность по память 

## Что хотелось бы реализовать 
- [ ] Считываниие настоящего курса любой валюты
    - [ ] Реквест на сайт ЦБ
    - [ ] Преобразование данных из JSON в необходимые структуры
    - [ ] Возврат настоящей стоимости валюты в рублях
    - [ ] Вывод доступных валют
    - [ ] Преобразование курса рубля к $currency_1 = k * currency_2$
- [ ] Накопление данных от ($t_{start}$, $t_{end}$, $\Delta_{measure}$)
    - [ ] Продолжительное считывание курса
    - [ ] Курс валют за прошедшее время
    - [ ] Изменение диапазона
- [ ] Поиск медианы и поиск медианы в реальном времени
- [ ] Поиск изменения с начала измерения в рублях и процентах от изначального 
- [ ] Клиент
    - [ ] Парсинг времени из консоли в *time_t*
    - [ ] Парсинг команд и хранение описания команд
    - [ ] Сабшел для быстрого вывода курса
    - [ ] Реализовать исполнение команд
        - [ ] Вывод курса конкректной валюты в настоящее время
        - [ ] Вывод курса валюты в указанное время
        - [ ] Изменение диапазона
        - [ ] Рисование графика валюты с помощью шрифта Брайля

## Архитектура 
``` mermaid
    classDiagram
    class  ExchangeUnit {
        ExchangeUnit()
        ExhangeUnit(time_t time)

        getRate(string rcurrency)
        getRate(string currency, string rcurrency)

        void getCurrencies(string* currencies, int* size)

        time_t time
        int size
        map <string, int> rate;
    }

    class ExchangeTable {
        ExchangeTable(left_time, right_time)
        ExchangeTable(left_time, right_time, delta)

        string raw()
        string raw(string currency)
        string raw(string* currencies, int size)
        string raw(string currency, string* currencies, int size)
        cc

        operator[ ]()

        time_t start
        time_t end
        time_t delta = 10
        int size
        ExchangeUnit* table
    }

    class CurrentExchangeAPI {
        getCurrencies(string* currencies, int* size)
        int getRate()
        int getRage(datetime)
    }

    class TinkoffAPI {
        TinkoffAPI(string token)
    }

    CurrentExchangeAPI --> TinkoffAPI
    

    ExchangeUnit --o ExchangeTable : table
```