#include <stdio.h> 
#include <limits.h> 

// Jumlah vertex pada graf 
#define V 9 

// Fungsi untuk mencari vertex dengan jarak terkecil yang belum
// dimasukkan ke shortest path tree
int minDistance(int dist[], bool sptSet[]) 
{ 
// Inisialisasi nilai min 
int min = INT_MAX, min_index; 

for (int v = 0; v < V; v++) 
	if (sptSet[v] == false && dist[v] <= min) 
		min = dist[v], min_index = v; 

return min_index; 
} 

// Fungsi untuk mencetak array jarak yang dibangun 
int printSolution(int dist[], int n) 
{ 
printf("Vertex \tDistance from Source\n"); 
for (int i = 0; i < V; i++) 
	printf("%d \t %d\n", i, dist[i]); 
} 

// Fungsi yang mengimplementasi algoritma single source shortest
// path Dijkstra pada graf yang direpresentasikan dalam bentuk
// matrix terhubung
void dijkstra(int graph[V][V], int src) 
{ 
	int dist[V];	 // Array output, dist[i] akan menyimpan jarak
					 // terpendek dari src ke i

	bool sptSet[V];  // sptSet[i] akan bernilai true jika vertex i
					 // ada pada path tree atau jarak terpendek dari
                     // src ke i adalah f

	// Inisialisasi semua jarak = INFINITE dan sptSet[] = false
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	// Jarak dari vertex awal ke dirinya sendiri selalu 0
	dist[src] = 0; 

	// Cari jarak terpendek untuk semua vertex 
	for (int count = 0; count < V-1; count++) 
	{ 
	// Pilih vertex dengan jarak terpendek dari set vertex yang belum
    // diproses. u selalu sama dengan src pada iterasi pertama
	int u = minDistance(dist, sptSet); 

	// Tandai vertex yang dipilih telah diproses
	sptSet[u] = true; 

	// Update nilai jarak vertex bersebelahan yang dipilih 
	for (int v = 0; v < V; v++) 

		// Update dist[v] hanya jika v tidak ada pada sptSet,
        // ada edge dari u ke v, and total jarak dari src ke v melalui u
        // lebih kecil dari nilai dist[v] sekarang
		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
									&& dist[u]+graph[u][v] < dist[v]) 
			dist[v] = dist[u] + graph[u][v]; 
	} 

	// print jarak array yang dibangun 
	printSolution(dist, V); 
} 
 
int main() 
{ 
int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
					{4, 0, 8, 0, 0, 0, 0, 11, 0}, 
					{0, 8, 0, 7, 0, 4, 0, 0, 2}, 
					{0, 0, 7, 0, 9, 14, 0, 0, 0}, 
					{0, 0, 0, 9, 0, 10, 0, 0, 0}, 
					{0, 0, 4, 14, 10, 0, 2, 0, 0}, 
					{0, 0, 0, 0, 0, 2, 0, 1, 6}, 
					{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
					{0, 0, 2, 0, 0, 0, 6, 7, 0} 
					}; 

	dijkstra(graph, 0); 

	return 0; 
} 
