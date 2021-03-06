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
обеспечивающие оптимальную алгоритмическую сложность расчетов и не избыточность по памяти

## Что хотелось бы реализовать 
- [ ] Считываниие настоящего курса любой валюты
    - [x] Реквест на сайт 1prime.com
    - [x] Преобразование данных из JSON в необходимые структуры
    - [x] Возврат настоящей стоимости валюты в рублях
    - [x] Вывод доступных валют
    - [ ] Преобразование курса рубля к $currency_1 = k * currency_2$
- [ ] Накопление данных от ($t_{start}$, $t_{end}$, $\Delta_{measure}$)
    - [ ] Продолжительное считывание курса
    - [ ] Курс валют за прошедшее время
    - [ ] Изменение диапазона
- [x] Поиск медианы и поиск среднего 
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

    class CurrentExchangeAPI {
        getCurrencies()
        getRate()
    }

    class OnePrimeExchangeAPI {
        getCurrencies()
        getRate()
    }

    class  CurrentExchangeUnit {
        CurrentExchangeUnit(api)

        getRate(string rcurrency)

        void getCurrencies(string* currencies, int* size)

        time_t time
        int size
        map <string, int> rate;
    }

    class SillyExchangeTable {
        SillyExchangeTable()
        makeRequest()
        operator[]()

        time_t start
        time_t end
        time_t delta = 10
        int size
        CurrentExchangeUnit* table
    }

    class OnePrimeAPI {
        
    }

    CurrentExchangeAPI --|> OnePrimeAPI
    
    Rate --o CurrentExchangeUnit : rates
    CurrentExchangeUnit --o SillyExchangeTable : table
    OnePrimeAPI --o CurrentExchangeUnit : api
```