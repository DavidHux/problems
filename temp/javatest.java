class Test {
    public static int X = 100;
    public final static int Y = 200;

    public Test() {
        System.out.println("Test构造函数执行");
        X = 1000;
        System.out.println("x is" + Integer.toString(X));
    }

    static {
        System.out.println("static语句块执行");
        X = 2000;
        System.out.println("x is" + Integer.toString(X));
    }

    {
        System.out.println("no static语句块执行");
    }

    public static void display() {
        System.out.println("静态方法被执行");
    }

    public void display_1() {
        System.out.println("实例方法被执行");
    }
}
class Singleton {
    private static Singleton singleton = new Singleton();
    public static int value1;
    public static int value2 = 0;

    private Singleton() {
        value1++;
        value2++;
    }

    public static Singleton getInstance() {
        return singleton;
    }

}

class Singleton2 {
    public static int value1;
    public static int value2 = 0;
    private static Singleton2 singleton2 = new Singleton2();

    private Singleton2() {
        value1++;
        value2++;
    }

    public static Singleton2 getInstance2() {
        return singleton2;
    }

}

public class javatest {
    // public static void main(String args[]) {
    // try {
    // Class.forName("Test");
    // Class.forName("Test");
    // } catch (ClassNotFoundException e) {
    // e.printStackTrace();
    // }

    // }
    

    public static void main(String[] args) {
        Singleton singleton = Singleton.getInstance();
        System.out.println("Singleton1 value1:" + singleton.value1);
        System.out.println("Singleton1 value2:" + singleton.value2);

        Singleton2 singleton2 = Singleton2.getInstance2();
        System.out.println("Singleton2 value1:" + singleton2.value1);
        System.out.println("Singleton2 value2:" + singleton2.value2);
    }

}