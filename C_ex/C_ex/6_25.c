//ong long distance(int ux, int uy, int vx, int vy) {
//    return (long long)pow(ux - vx, 2) + (long long)pow(uy - vy, 2);
//}
//
//
//bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
//    /* Բ���ھ����ڲ� */
//    if (x1 <= xCenter && xCenter <= x2 && y1 <= yCenter && yCenter <= y2) {
//        return true;
//    }
//    /* Բ���ھ����ϲ� */
//    if (x1 <= xCenter && xCenter <= x2 && y2 <= yCenter && yCenter <= y2 + radius) {
//        return true;
//    }
//    /* Բ���ھ����²� */
//    if (x1 <= xCenter && xCenter <= x2 && y1 - radius <= yCenter && yCenter <= y1) {
//        return true;
//    }
//    /* Բ���ھ����� */
//    if (x1 - radius <= xCenter && xCenter <= x1 && y1 <= yCenter && yCenter <= y2) {
//        return true;
//    }
//    /* Բ���ھ����Ҳ� */
//    if (x2 <= xCenter && xCenter <= x2 + radius && y1 <= yCenter && yCenter <= y2) {
//        return true;
//    }
//    /* �������Ͻ� */
//    if (distance(xCenter, yCenter, x1, y2) <= radius * radius) {
//        return true;
//    }
//    /* �������½� */
//    if (distance(xCenter, yCenter, x1, y1) <= radius * radius) {
//        return true;
//    }
//    /* �������Ͻ� */
//    if (distance(xCenter, yCenter, x2, y2) <= radius * radius) {
//        return true;
//    }
//    /* �������½� */
//    if (distance(xCenter, yCenter, x1, y2) <= radius * radius) {
//        return true;
//    }
//    /* �޽��� */
//    return false;
//}