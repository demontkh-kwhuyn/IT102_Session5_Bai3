#include <stdio.h>

int main() {
    // Khởi tạo dữ liệu mẫu cho 4 bệnh nhân (Có thể thay đổi để test)
    int tuoi_benh_nhan[4] = {45, 75, -5, 30};
    int co_bao_hiem[4]     = {1, 0, 2, 0};     // Bệnh nhân 3 có BHYT lỗi (nhập 2)
    int phi_kham[4];

    long tong_doanh_thu = 0;
    int tong_ca_uu_tien = 0;

    printf("=== MODULE TIEP NHAN VA XEP HANG KHAM BENH MEDCARE ===\n\n");

    for (int i = 0; i < 4; i++) {
        // 1. Kiểm tra lỗi BHYT sai quy chuẩn (chỉ chấp nhận 0 hoặc 1)
        if (co_bao_hiem[i] != 0 && co_bao_hiem[i] != 1) {
            co_bao_hiem[i] = 0; // Tự động quy về 0 để tránh thất thoát doanh thu
        }

        // 2. Kiểm tra lỗi độ tuổi dị biệt
        if (tuoi_benh_nhan[i] <= 0 || tuoi_benh_nhan[i] > 120) {
            phi_kham[i] = 0;
            printf("Benh nhan %d: Tuoi bat hop le (%d) -> Phi: 0 VND | Luong: LOI DU LIEU\n", 
                   i + 1, tuoi_benh_nhan[i]);
        } else {
            // Tính phí khám dựa trên BHYT
            if (co_bao_hiem[i] == 1) {
                phi_kham[i] = 40000; // Giảm 80% từ 200.000 VNĐ
            } else {
                phi_kham[i] = 200000; // Giữ nguyên giá gốc
            }

            // Cộng dồn doanh thu
            tong_doanh_thu += phi_kham[i];

            // Phân luồng ưu tiên (> 70 tuổi)
            if (tuoi_benh_nhan[i] > 70) {
                tong_ca_uu_tien++;
                printf("Benh nhan %d: %d tuoi, BHYT: %d -> Phi: %d VND | Luong: UU TIEN\n", 
                       i + 1, tuoi_benh_nhan[i], co_bao_hiem[i], phi_kham[i]);
            } else {
                printf("Benh nhan %d: %d tuoi, BHYT: %d -> Phi: %d VND | Luong: THUONG\n", 
                       i + 1, tuoi_benh_nhan[i], co_bao_hiem[i], phi_kham[i]);
            }
        }
    }

    // 3. Tổng hợp báo cáo ca trực
    printf("\n-------------------------------------------------\n");
    printf("TONG KET CA TRUC:\n");
    printf("- Tong doanh thu thuc te: %ld VND\n", tong_doanh_thu);
    printf("- Tong so ca thuoc luong UU TIEN: %d\n", tong_ca_uu_tien);

    return 0;
}