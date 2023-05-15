#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data; 
    struct Node *next; // Sonraki düğümün adresini tutan pointer
};

struct Queue {
    struct Node *front; // Kuyruğun önündeki düğüm
    struct Node *rear; // Kuyruğun arkasındaki düğüm
};

// Kuyruğa ekleme işlemi bu kısımda yapılır
void enqueue(struct Queue *queue, int data) {
    // Yeni düğüm oluşturulur
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    // Kuyruk boşsa yeni düğümü kuyruğun önüne ve arkasına yerleştirdik
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    // Kuyruğun arkasına yeni düğümü ekliyoruz
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Kuyruktan silme işlemi yapıyoruz
void dequeue(struct Queue *queue) {
    // Kuyruk boşsa uyarı mesajı verilir
    if (queue->front == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }
    // Kuyruğun önündeki düğümü silinir
    struct Node *temp = queue->front;
    queue->front = queue->front->next;
    // Kuyruk boşsa kuyruğun arkasını da NULL yapılır
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
}

// Kuyruğu görüntüleme işlemi burda gerçekleşir
void display(struct Queue *queue) {
    // Kuyruk boşsa uyarı mesajı verilir
    if (queue->front == NULL) {
        printf("Kuyruk bos.\n");
        return;
    }
    // Kuyruktaki tüm düğümleri görüntülenir
    struct Node *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Yeni bir kuyruk oluşturma
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;

    int choice, data;

    while (1) {
        printf("1. Ekleme\n2. Silme\n3. Goruntuleme\n4. Cikis\nSecim: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Veri: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Gecersiz secim.\n");
        }
    }

    return 0;
}
