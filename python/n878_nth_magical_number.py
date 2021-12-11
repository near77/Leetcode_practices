class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        a_times = 1
        b_times = 1
        product_array = []
        while a*a_times != b*b_times:
            if a*a_times < b*b_times:
                product_array.append(a*a_times)
                a_times += 1
            elif a*a_times > b*b_times:
                product_array.append(b*b_times)
                b_times += 1
        product_array.append(a*a_times)
        num_per_common_product = len(product_array)
        num_of_common_product = n // num_per_common_product
        res = num_of_common_product*product_array[-1]%(10**9+7)+product_array[n-num_per_common_product*num_of_common_product-1] if n%num_per_common_product != 0 else num_of_common_product*product_array[-1]%(10**9+7)
        return res%(10**9+7)
                