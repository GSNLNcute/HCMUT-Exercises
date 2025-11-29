import sympy as sp
import numpy as np
import matplotlib.pyplot as plt

# 1. Nhập biểu thức điện thế V(x, y)
x, y = sp.symbols('x y')
expr_str = input("Nhập vào biểu thức V(x, y): ")

try:
    V = sp.sympify(expr_str)
except Exception:
    print("Lỗi: Biểu thức không hợp lệ!")
    exit()

# 2. Tạo lưới điểm
X_vals = np.linspace(-10, 10, 41)
Y_vals = np.linspace(-10, 10, 41)
X, Y = np.meshgrid(X_vals, Y_vals)

# 3. Tính đạo hàm Ex, Ey
dVdx = sp.diff(V, x)
dVdy = sp.diff(V, y)

# 3.1 Tạo hàm lambda (tự động tránh lỗi log(x≤0) bằng cách dùng 'numpy' và xử lý nan)
fV = sp.lambdify((x, y), V, "numpy")
fEx = sp.lambdify((x, y), -dVdx, "numpy")
fEy = sp.lambdify((x, y), -dVdy, "numpy")

# 3.2 Tính giá trị trên lưới và thay các giá trị không xác định bằng nan
def safe_eval(f, X, Y):
    try:
        arr = f(X, Y)
        arr = np.array(arr, dtype=float)
        arr[~np.isfinite(arr)] = np.nan     # tránh lỗi log(x<=0), chia 0, v.v.
        return arr
    except Exception:
        return np.full_like(X, np.nan)

V_grid = safe_eval(fV, X, Y)
Ex_grid = safe_eval(fEx, X, Y)
Ey_grid = safe_eval(fEy, X, Y)

# Độ lớn điện trường
E_mag = np.sqrt(Ex_grid**2 + Ey_grid**2)

# Cho các vector E có độ dài bằng nhau
E_mag_nozero = np.where(E_mag == 0, 1, E_mag)
Ex_unit = Ex_grid / E_mag_nozero
Ey_unit = Ey_grid / E_mag_nozero

# Loại bỏ vùng không xác định của điện thế
mask = np.isnan(V_grid)
Ex_unit[mask] = np.nan
Ey_unit[mask] = np.nan
E_mag[mask] = np.nan

step = 2   # giảm một nửa số mũi tên
X2 = X[::step, ::step]
Y2 = Y[::step, ::step]
Ex_unit2 = Ex_unit[::step, ::step]
Ey_unit2 = Ey_unit[::step, ::step]
E_mag2 = E_mag[::step, ::step]

# 4. Vẽ đồ thị
fig = plt.figure(figsize=(14, 6))

#  Đồ thị điện thế V(x, y) 3D với chiều cao biểu thị độ lớn
ax1 = fig.add_subplot(1, 2, 1, projection='3d')
surf = ax1.plot_surface(X, Y, V_grid, cmap='jet')

ax1.set_title(f"Mặt Điện thế V(x,y)\n{expr_str}", fontsize=12)
ax1.set_xlabel("x")
ax1.set_ylabel("y")

# Đặt zlabel sao cho nằm hẳn bên trái trục z, không bị che bởi colorbar
ax1.set_zlabel("V (volts)", labelpad=12)  
ax1.zaxis.set_rotate_label(False)  
ax1.zaxis.label.set_rotation(90)  

# Colorbar của V
cbar1 = fig.colorbar(surf, ax=ax1, shrink=0.6, pad=0.15)  # thêm pad để tránh che trục
cbar1.set_label("Giá trị V")

#  Biểu diễn vector cường độ điện trường E
ax2 = fig.add_subplot(1, 2, 2)
q = ax2.quiver(X2, Y2, Ex_unit2, Ey_unit2, E_mag2, cmap='jet',
               scale=30, width=0.003)

ax2.set_title("Vector Cường độ Điện trường E", fontsize=12)
ax2.set_xlabel("x")
ax2.set_ylabel("y")

# Colorbar của E
cbar2 = fig.colorbar(q, ax=ax2)
cbar2.set_label("Độ lớn E")

plt.tight_layout()
plt.show()
