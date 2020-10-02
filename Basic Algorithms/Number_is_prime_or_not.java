// To Check whether a number is prime or not

class Number_is_prime_or_not {
    public static void main(String args[]) {
            Scanner sc = new Scanner(System.in);

                int n = sc.nextInt();

                int count = 0;
                for(int div = 2; div * div <=n; div++ ){
                    if(n % div == 0){
                        count++;
                        break;
                    }
                }
                if(count == 0 && n!= 1){
                    System.out.println("Prime");
                }
                else{
                    System.out.println("Not Prime");
                }
            }
        }
