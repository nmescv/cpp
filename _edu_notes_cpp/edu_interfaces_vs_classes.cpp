Интерфейсы vs. классы

Обсуждая с различными людьми — в большинстве своём опытными разработчиками — классический труд "Приёмы объектно-ориентированного проектирования. Паттерны проектирования" Гаммы, Хелма и др., я с изумлением встретил полное непонимание одного из базовых подходов ООП — различия классов и интерфейсов.

Авторам книги этот вопрос кажется настолько прозрачным, что они посвящают ему едва две страницы, предполагая, что читателям всё это и так должно быть очевидно. И, действительно, это не вызвало у меня никаких вопросов — это казалось настолько само собой разумеющимся, что, когда я некоторое время назад встретил у сразу нескольких программистов откровенное непонимание концепции, я даже не смог найти слов, чтобы объяснить её суть.

Поэтому я попытался систематизировать своё понимание вопроса в этой заметке.

Главное отличие класса от интерфейса — в том, что класс состоит из интерфейса и реализации.

Любой класс всегда неявно объявляет свой интерфейс — то, что доступно при использовании класса извне. Если у нас есть класс "Ключ" и у него публичный метод "Открыть", который вызывает приватные методы "Вставить", "Повернуть" и "Вынуть", то интерфейс класса "Ключ" состоит из метода "Открыть". Когда мы унаследуем какой-то класс от класса "Ключ", он унаследует этот интерфейс.

Кроме этого интерфейса, у класса есть также реализация — методы "Вставить", "Повернуть", "Вынуть" и их вызов в методе "Открыть". Наследники "Ключа" наследуют вместе с интерфейсом и реализацию.

И вот здесь таятся проблемы. Предположим, у нас есть некая модель, которая предполагает использование ключа для открытия двери. Она знает интерфейс "Ключа" и поэтому вызывает метод "Открыть".

Но, предположим, некоторые двери открываются не таким вот поворотным ключом, а магнитной карточкой — которая ведь тоже по своей сути ключ! Интерфейс этой карточки никак принципиально не отличается от интерфейса обычного ключа — можно "Открыть" ключом, а можно "Открыть" карточкой.

И мы хотим сделать класс "Магнитную Карточку", который тоже будет содержать интерфейс "Ключа". Для этого мы унаследуем "Магнитную Карточку" от "Ключа". Но вместе с интерфейсом унаследовалась и реализация, которая в методе "Открыть" вызывает методы "Вставить", "Повернуть" и "Вынуть" — а это совершенно не подходит для Магнитной Карточки.

Нам придётся самое меньшее перегружать в "Магнитной Карточке" реализацию метода "Открыть", используя уже последовательность "Вставить, Провести и Вынуть". Это уже плохо, потому что мы не знаем детали реализации класса "Ключ" - вдруг мы упустили какое-то очень важное изменение данных, которое должно было быть сделано — и было сделано в методе "Ключ::Открыть"? Нам придётся лезть во внутреннюю реализацию "Ключа" и смотреть, что и как — даже если у нас есть такая техническая возможность (open source навсегда и так далее), это грубое нарушение инкапсуляции, которое ни к чему хорошему не приведёт.

Именно так и пишут Гамма и др.: "наследование является нарушением инкапсуляции!"

Можете попробовать самостоятельно поразмышлять над такими вопросами:
— Что делать с тем фактом, что "Ключ" вставляется просто в скважину, а "Магнитная Карточка" - обязательно сверху (не посередине и не снизу)?
— Что делать, когда нам понадобиться сделать "Бесконтактную Карточку", которую надо не вставлять, а подносить?

Правильный подход к данному вопросу — отделить интерфейс от реализации. Во многих современных языках для этого предусмотрен специальный синтаксис. В отсталых языках можно использовать хаки, например, в Цэ-два-креста — чисто абстрактные классы и множественное наследование (извините за обсценную лексику — из песни слова не выкинешь).

Мы должны опираться на интерфейсы, а не классы.

Объявим интерфейс "Ключ", содержащий метод "Открыть".

Объявим класс "Поворотный Ключ", реализующий интерфейс "Ключ" при помощи своих методов "Вставить, Повернуть и Вынуть".

Объявим класс "Магнитная Карточка", тоже реализующий интерфейс "Ключ", но уже по-своему — и без каких-либо неприятных пересечений с реализацией "Поворотного Ключа". Этого помогло нам достичь отделение интерфейса от реализации.

Всегда помните об общем принципе: нам нужно использовать не класс, а интерфейс. Нам не важно, что это за штука — поворотный ключ или магнитная карточка, — нам важно, что им можно открыть дверь. То есть, вместо того, чтобы задумываться о природе объекта, мы задумываемся о способах его использования.

Вам может показаться странным, но это именно то, что отличает человека от животного — использование интерфейсов вместо классов. Вы наверняка помните классический опыт с обезьяной, которую приучили гасить огонь водой из ведёрка; а потом поставили ведёрко на плот посреди бассейна, но обезьяна всё равно бегала по мостику на плот и черпала воду из ведёрка, вместо того, чтобы черпать воду прямо из бассейна. То есть обезьянка использовала класс "Вода-в-Ведёрке" вместо интерфейса "Вода" (и даже больше, скажу по секрету: вместо интерфейса "Средство-для-Тушения").

Когда мы мыслим классами — уподобляемся животным. Люди мыслят (и программируют) интерфейсами.

Использование интерфейсов даёт большие возможности. Например, класс может реализовывать несколько интерфейсов: класс "Ключ-от-Домофона" может содержать интерфейсы "Ключ" и "Брелок".

Что касается наследования классов, которое, как вы помните, нарушает инкапсуляцию — часто вместо наследования лучше использовать делегирование и композицию. Не забыли "Бесконтактную Карточку"? Так хочется сделать её родственной "Магнитной Карточке"! (Например, чтобы знать, что их обе можно положить в "Отделение-для-Карточек" в "Бумажнике".) Однако у них, кажется, нет ничего общего: интерфейс "Ключ" их роднит в той же мере, что и "Поворотный Ключ" с "Ключом-от-Домофона".

-------
Не согласен. Думать в терминах классов очень полезно. Интерфейсы полезны, когда нужно выстроить иерархию неких абстрактных методов типа icomparable. Но когда строится иерархия однотипных, похожих друг на друга классов полезно применять наследование. Интерфейсы влекут за собой избыточное кодирование, изменение означает полную переработку по всей иерархии. В наследовании есть очень полезная штука с дефолтной реализацией плюс еще могут быть поля. Короче на одних только интерфейсах каши не сваришь.
Интерфейсы кстати тоже могут нарушать инкапсуляцию - например, мне нужно выполнять какой-то базовый метод так, а не иначе - спасает наследование реализации. А интерфейсы нарушают. 

ПС: пример надуман. можно наследовать "Карточку" и "Ключ" от общего абстрактного класса. 
ППС: Если у классов есть общие поля, то композицией не отделаешься. Имхо естественно наследовать реализацию.
ПППС: Бывают те кто пришли из спп - они пытаются контракты сделать через наследование. И сразу перестроиться нельзя.

-------

Решение? Делаем класс (а может, и интерфейс — подумайте, что здесь подойдёт лучше) "Карточка", реализующий интерфейс "Ключ" за счёт делегирования "Магнитной Карточке" либо же "Бесконтактной Карточке". А чтобы узнать, что такое делегирование и композиция, а так же при чём тут абстрактная фабрика — обратитесь к книгам, посвящённым паттернам проектирования.

У использования интерфейсов вместо классов есть ещё много преимуществ. Вы сами сможете увидеть их на практике. Оставайтесь людьми!

P.S. К моему удивлению, я не смог найти на "Хабрахабре" ни блога, посвящённого ООП, ни блога, посвящённого программированию в целом. Если они есть — укажите, пожалуйста, а пока за неимением лучших вариантов размещаю в персональном блоге.

-------
Интерфейс есть совокупностость методов, описывающая взаимодействие с объектом, и подходит для множественного наследования. 
А абстрактный класс, это уже всё-таки класс, который может содержать не только абстрактные методы, но и поля, операторы, шаблонные методы.

Quasar_ru 17 июня 2012 в 15:20   –8     
Интерфейс — класс в котором все методы абстрактные.

s0L 17 июня 2012 в 15:34   +8     
Это частный случай, например в С++, т.к. там нет отдельных конструкций для описания интерфейсов. Более того, в С++ достаточно хотя бы одного pure virtual метода, чтобы класс стал абстрактным.

Quasar_ru 17 июня 2012 в 15:41   –3     
В Java тоже достаточного одного abstract метода, что бы бы класс стал абстрактным и что? Собственно то что меня тут минусуют хорошо показывает, кругозор людей. Хорошо хоть один человек нашелся, который знает что такое C++ и его особенности. Да в C++ есть множественное наследование и нет необходимости в ключевом слове interface как в Java, но сути это не меняет. Интерфейс и есть полностью абстрактный класс, то есть ни один из его методов не имеет реализации.

leventov 17 июня 2012 в 15:59   +6     
Мне кажется имелся ввиду более академический (ГОФ/Макконнелл) подход к определениям: любой класс обладает интерфейсом, в то же время полностью абстрактный класс — некоторое его выражение на уровне кода, потому что по смыслу совпадает со стоим интерфейсом.

Интерфейс — абстрактный класс, в котором вообще нет реализации, только сигнатуры методов.

Отличие у них всего одно — концептуальное: интерфейс это "поведение" без реализации; абстрактный класс — частичная реализация какого-либо поведения (конкретная реализация переложена на плечи потомков). 
Из этого отличия как раз и вытекают все свойства интерфейсов: реализация методов в них бессмысленна (и противоречит концепции), т.к. автоматически превращает интерфейс в абстрактный класс (обратное тоже верно — абстрактный класс содержащий только абстрактные методы можно считать интерфейсом); множественная реализация интерфейсов, в отличие от множественного наследования, разрешена т.к. не может породить конфликтов реализаций; и т.д.

------------
Example:
"C:\dev\cpp\interface_abs_edu\main.cpp"

#include "gen.h"
#include "utils.h"
#include "ikey.h"
#include "key.h"

class MyKey : public Key
{
public:
    MyKey() { cout << "MyKey: >> Constructor." << endl;};
   ~MyKey(){ cout << "MyKey: >> Destructor." << endl; };    
};


class MagneticKey : public Key
{
public:
   MagneticKey() { cout << "MgntKey: >> Constructor." << endl;};
  ~MagneticKey(){ cout << "MgntKey: >> Destructor." << endl;};    
   void Open()
   {
        cout << "MgntKey: -> Open." << endl;

   }
    
};


class iKey
{
public:
    virtual ~iKey(){}        
    virtual void Open() =0;    
private:
    int _key_type;
};

class TurnKey : public iKey
{
public:
   TurnKey(){ cout << "TurnKey: >> Constructor." << endl;};
  ~TurnKey(){ cout << "TurnKey: >> Destructor." << endl;};
   void Open()
   {
        cout << "TurnKey: -> Open." << endl;
        Insert();
        Turn();
        Remove();
    }
    
private:
    void Insert() { cout << "TurnKey: Insert." << endl; };
    void Turn()   { cout << "TurnKey: Turn." << endl; };
    void Remove() { cout << "TurnKey: Remove." << endl; };    
};

class MgntKey : public iKey
{
public:
   MgntKey(){ cout << "MgntKey: >> Constructor." << endl;};
  ~MgntKey(){ cout << "MgntKey: >> Destructor." << endl;};
   void Open()
   {
        cout << "MgntKey: -> Open." << endl;
        Insert();
        Slide();
        Remove();
    }
    
private:
    void Insert() { cout << "MgntKey: Insert." << endl; };
    void Slide()  { cout << "MgntKey: Slide." << endl; };
    void Remove() { cout << "MgntKey: Remove." << endl; };
    
};

void test_inherit()
{
    Key* _key = new MagneticKey();
    _key->Open();

    delete _key;

    //MagneticKey _mgntKey;
    //_mgntKey.Open();
}


int main()
{
    cout << "APP start:" << endl;
    iKey* _key = new TurnKey();
    _key->Open();

    _key = new MgntKey();
    _key->Open();

    delete _key;
    
    cout << "APP END:" << endl;
    // getch();
}




