// Use line comments for short comments.

/*
 * Use .cpp for C++ implementation files.
 * Use .h for header files.
 */

/*
 * Use block comments for long comments that don't fit in a single line.  For
 * example, for this comment.
 */

// Indentation is 4 spaces.  No tabs.

// Maximum line length is 80 characters.
///////////////////////////////////////////////////////////////////////////////

// Remove trailing whitespace before newline.

// Use std::endl for newlines in source files instead of '\n'.

struct FooBase
{
// Explicitly specify access specifier.
public:
    virtual void someFooBaseVirtualMethod() = 0;
}

// Place base classes on the same line.
class FooChild: public FooBase
{
};

/*
 * If base classes list doesn't fit, place every class from a new intended with
 * 4 spaces line.
 */
class Foo:
    public FooBase,
    public AnotherFooBase
{
public:
    Foo(int param):
        param_(param),           // Use member initialization list.
        param2_(param)           // Keep members in order they appear
                                 // in the class definition!
    {
    }

    /*
     * Write both braces on different lines even when function/method body is
     * empty.
     */
    virtual ~Foo()
    {
    }

    /*
	 * Duplicate 'virtual' keyword and use C++11 'override' specifier
	 * when overriding virtual methods.
	 */
    virtual void someFooBaseVirtualMethod() override;

    void someOtherMethod();

    int someVariable;

    /*
     * Use TODO: comment for marking an undone part of code,
     * e.g. next task or proposal (don't forget to create an issue).
     */

    // Use FIXME: comment to mark code lines requiring fixing/patching.

    /*
     * Use XXX: to say 'I know it's a dirty code here, I'm going to fix it
     * shortly'.
     */

// Place private variables at the end of the class declaration.
private:
    // Add a trailing underscore '_' to private class fields' names.
    int someVar_;
    // Do not use a trailing underscore '_' for private constants.
    const static int someConstant = 42;
    // Use constatnts whenever possible, avoid magic numbers.
    const static int importantConstant = 10;
    // Use constexpr for assigning a non-integral constant fields.
    constexpr static double floatingPointConstant = 3.14159265358789;

public:
    /*
     * Use the name of private field without trailing underscore for a getter.
     * Declare getters as const member functions.
     */
    int someVar() const
    {
        return someVar_;
    }

    // Use the setFooBar as the setter name for the fooBar_ private field.
    void setSomeVar(int someVar)
    {
        someVar_ = someVar;
    }
};

void Foo::someFooBaseVirtualMethod()
{
    // When splitting long expression, leave operator at the end of the line.
    while(condition &&
          someVar > importantConstant)
    {
        someOtherMethod();
    }

    /*
     * In do-while place 'while' on the same line as closing brace.  This is the
     * only case when brace is not alone on the line.
     */
    do
    {
        printf("in a do-while loop\n");
    } while(condition);

    // if, for, while, do-while don't have a space before '('.
    for(int i = 0; i < importantConstant; i++)
    {
        // Don't omit curly braces even if body is a single statement.
        if(condition)
        {
            this->someOtherMethod();
        }
        else
        {
            printf("else\n");
        }
    }

    // Format range-based for loops like this:
    for(int x : container)
    {
        process(x);
    }

    /*
     * In switch statements put an empty line after 'break' and mark fall-through
     * cases explicitly.
     */
    switch(something)
    {
    case AAA:
        aaa();
        break;

    case BBB:
        bbb();
        // Fall-through

    case CCC:
    case DDD:
        ccc();
        break;

    default:
        break;
    }

    /*
     * General rule: if an expression continues after opening parentheses, it
     * must be started at the column next to parentheses when splitted to
     * several lines.  Otherwise, if after the parentheses a newline comes, all
     * the following lines must be indented with 4 more spaces from the
     * original indentation.  The closing parentheses is placed at the end of
     * the last line.
     */

    // Indent function arguments when breaking function call into multiple lines.
    someFunctionThatHasManyArguments(first * aaaaaaaaaaa,
                                     second,
                                     third);

    /*
     * If you can't fit some argument, place every argument on a separate line
     * indented with 4 spaces from its normal indentation.
     */
    anotherFunctionThatHasManyArguments(
        first * aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa,
        second,
        third);

    /*
     * If a long expression doesn't fit, start it with 8 spaces from its normal
     * identation.
     */
    someAbnormallyLongVariableName = anotherAbnormallyLongVariableName +
            theSecondAbnormallyLongVariableName +
            theThirdAbnormallyLongVariableName * somethingShort;

    // Use C++ casts instead of C ones.
    void *a = reinterpret_cast<void *>(b);
    int c = static_cast<int>(3.14f);

    // Prefer explicitly specifing namespaces to using it for the whole file.
    std::cout << "Hello, world" << std::endl;

    /*
     * Don't use spaces between closing angle brackets.
     * It is not an error in C++11.
     */
    std::vector<std::pair<int, int>> vec;

    /*
     * Use the 'auto' C++11 keyword when it's obvious or irrelevant what the
     * type is, e.g. iterator or closure.
     */
    for(auto it = vec.begin(); it != vec.end(); it++)
    {
        it.first = it.second;
    }

    // Use 'nullptr' instead of NULL.
    int *hereWillBeABigArray = nullptr;

    /*
     * Treat lambdas as normal functions, especially braces.
     * Respect function arguments code style as well.
     */
    for_each(
        vec.begin(),
        vec.end(),
        [&](std::pair<int, int> element)
        {
            element.second = 42;
        });
}

/*
 * Prefer unnamed namespaces for file-scope definitions
 * Do not make first-level indentation in these namespaces
 */
namespace {

int functionVisibleOnlyInCurrentFile();

// Write a comment to mark the namespace closing brace
} // unnamed namespace


#ifdef MACRO_1
// Write a comment in a closing conditional macro
#endif // MACRO_1
