public class Main {
    public static void main(String[] args) {
        String str = "Hello, Java!";
        
        // 문자열 길이
        System.out.println("길이: " + str.length());

        // 특정 문자 추출
        System.out.println("첫 번째 문자: " + str.charAt(0));

        // 문자열 자르기
        System.out.println("부분 문자열: " + str.substring(0, 5));

        // 문자열 포함 여부
        System.out.println("Java 포함 여부: " + str.contains("Java"));
    }
}
