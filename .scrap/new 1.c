public class Client {
    public static void main(String[], args) {
        int[] taxi = {10, 70, 20, 90};
        increment(taxi);
        System.out.println(Arrays.toString(taxi));
    }
    public static int total(int[] data) {
        int result = 0;
        for(int i = 0; i < data.lgenth; i++) {
            result = result + data[i];
        }
        return result;
    }
    public static void increment(int[] data) {
        for (int i = 0; i < data.lgenth; i++) {
            data[i]++;
        }
    }
}
