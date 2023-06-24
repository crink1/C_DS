//#define T 243
//#define N 5
//#define M 6
//
//int mask_bits[T][N];
//int iv_count[T], ev_count[T];
//int inner_score[T], inter_score[T][T];
//int d[N][T][M + 1][M + 1];
//
//// �ھӼ�ķ���
//const int score[3][3] = {
//    {0, 0, 0},
//    {0, -60, -10},
//    {0, -10, 40}
//};
//
//int dfs(int row, int premask, int iv, int ev, int m, int tot) {
//    if (row == m || (iv == 0 && ev == 0)) {
//        return 0;
//    }
//    // �����״̬�Ѿ�������𰸣���ֱ�ӷ���
//    if (d[row][premask][iv][ev] != -1) {
//        return d[row][premask][iv][ev];
//    }
//    // ʹ�����ã��򻯴���
//    int* res = &d[row][premask][iv][ev];
//    // �Ϸ�״̬����ʼֵΪ 0
//    *res = 0;
//    for (int mask = 0; mask < tot; mask++) {
//        // mask �����������������ܳ��� iv �������������ܳ��� ev
//        if (iv_count[mask] > iv || ev_count[mask] > ev) {
//            continue;
//        }
//        *res = fmax(*res, dfs(row + 1, mask, iv - iv_count[mask], ev - ev_count[mask], m, tot)
//            + inner_score[mask]
//            + inter_score[premask][mask]);
//    }
//    return *res;
//}
//
//void init_data(int m, int n, int tot) {
//    memset(mask_bits, 0, sizeof(mask_bits));
//    memset(iv_count, 0, sizeof(iv_count));
//    memset(ev_count, 0, sizeof(ev_count));
//    memset(inner_score, 0, sizeof(inner_score));
//    memset(inter_score, 0, sizeof(inter_score));
//
//    // �������ڷ���
//    for (int mask = 0; mask < tot; mask++) {
//        int mask_tmp = mask;
//        for (int i = 0; i < n; i++) {
//            int x = mask_tmp % 3;
//            mask_bits[mask][i] = x;
//            mask_tmp /= 3;
//            if (x == 1) {
//                iv_count[mask]++;
//                inner_score[mask] += 120;
//            }
//            else if (x == 2) {
//                ev_count[mask]++;
//                inner_score[mask] += 40;
//            }
//            if (i > 0) {
//                inner_score[mask] += score[x][mask_bits[mask][i - 1]];
//            }
//        }
//    }
//    // �����м����
//    for (int i = 0; i < tot; i++) {
//        for (int j = 0; j < tot; j++) {
//            inter_score[i][j] = 0;
//            for (int k = 0; k < n; k++) {
//                inter_score[i][j] += score[mask_bits[i][k]][mask_bits[j][k]];
//            }
//        }
//    }
//}
//
//int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
//    int tot = pow(3, n);
//    init_data(m, n, tot);
//    // ���仯�������飬��ʼ��Ϊ -1����ʾδ��ֵ
//    memset(d, -1, sizeof(d));
//    return dfs(0, 0, introvertsCount, extrovertsCount, m, tot);
//}