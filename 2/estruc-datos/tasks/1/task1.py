"""
Jose David Ruano Burbano
Estructura de datos
8982982

"""
# Punto 1 

def split(cad, step):
    ans = []
    palabra_actual = ""
    
    for caracter in cad:
        if caracter == step:
            if palabra_actual:
                ans.append(palabra_actual)
                palabra_actual = ""
        else:
            palabra_actual += caracter
    
    if palabra_actual:
        ans.append(palabra_actual)
    
    return  ans
# Punto 2
def obtenerSumas(mat):
    N = len(mat)
    sumas = [0] * (2 * N - 1)

    for i in range(N):
        for j in range(N):
            sumas[i + j] += mat[i][j]

    return sumas

# Punto 3

def obtenerMayorPosicion(cad1, cad2):
    diccionario_resultado = {}
    longitud_cad1 = len(cad1)
     
    for char in cad2:
        diccionario_resultado[char] = -1
    for i in range(longitud_cad1 - 1, -1, -1):
        char = cad1[i]
        if diccionario_resultado.get(char) == -1:
            diccionario_resultado[char] = i

    return diccionario_resultado

# Punto 4

def obtenerDosMayores(lista):
    if len(lista) < 2:
        raise ValueError("La lista debe tener al menos dos elementos para obtener los dos mayores.")
    
    # Inicializar las dos variables para almacenar los dos mayores números
    
    if lista[1] > lista[0]:
        mayor1 = lista[1]
        mayor2 = lista[0]
    elif lista[0] > lista[1]:
        mayor1 = lista[0]
        mayor2 = lista[1]
    elif lista[0] == lista[1]:
        mayor1 = lista[0]
        mayor2 = lista[0]
        
    # Recorrer la lista a partir del tercer elemento
    for num in lista[2:]:
        if num > mayor1:
            mayor2 = mayor1
            mayor1 = num
        elif num > mayor2:
            mayor2 = num
            

    return (mayor1, mayor2)

# Punto 5
def lectura_e_impresion():
    
    num_ejecuciones = int(input())

    for _ in range(num_ejecuciones):
        
        lista = []
        for _ in range(2):
            linea = input().split()
            lista.extend(map(int, linea))

        
        primer_valor_mayor, segundo_valor_mayor = obtenerDosMayores(lista)

        
        print(f"Primer valor mayor --> {primer_valor_mayor}, Segundo valor mayor --> {segundo_valor_mayor}")

# Punto 6

def mostrarDivisores(N):
    divisores = []
    suma_divisores = 0

    for i in range(1, N + 1):
        if N % i == 0:
            divisores.append(i)
            suma_divisores += i

    print(f"Divisores número {N}:")
    for i in range(len(divisores) - 1):
        print(f"--> {divisores[i]},")
    print(f"--> {divisores[-1]}")

    print(f"Suma de los divisores del número {N}: {suma_divisores}")
