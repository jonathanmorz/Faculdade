import heapq

def dijkstra(grafo, origem):
    # Dicionário para armazenar a menor distância da origem até cada vértice
    distancias = {vertice: float('inf') for vertice in grafo}
    distancias[origem] = 0
    
    antecessores = {vertice: None for vertice in grafo}
    
    # Fila de prioridade guarda tuplas: (distancia_atual, vertice)
    fila = [(0, origem)]
    
    while fila:
        dist_atual, vertice_atual = heapq.heappop(fila)
        
        # Se a distância na fila for maior que a registrada, ignora
        if dist_atual > distancias[vertice_atual]:
            continue
            
        # Explora os vizinhos do vértice atual
        for vizinho, peso in grafo[vertice_atual].items():
            distancia = dist_atual + peso
            
            # Se encontrou um caminho menor, atualiza, registra o antecessor e adiciona à fila
            if distancia < distancias[vizinho]:
                distancias[vizinho] = distancia
                antecessores[vizinho] = vertice_atual 
                heapq.heappush(fila, (distancia, vizinho))
                
    return distancias, antecessores

def reconstruir_caminho(antecessores, origem, destino):
    caminho = []
    atual = destino
    
    while atual is not None:
        caminho.append(atual)
        atual = antecessores[atual]
        
    caminho.reverse()
    
    # Verifica se o nó de destino é alcançável a partir da origem
    if caminho[0] == origem:
        return " -> ".join(caminho)
    return "Não há caminho disponível"

grafo_exemplo = {
    '1': {'2': 15, '3': 9},
    '2': {'4': 2},
    '3': {'2': 4, '4': 3, '5': 16},
    '4': {'5': 6, '6': 21},
    '5': {'6': 7},
    '6': {}
}

origem = str('1')
distancias, antecessores = dijkstra(grafo_exemplo, origem)

print(f"Resultados a partir do vértice '{origem}':\n")
for vertice in sorted(distancias.keys()):
    dist = distancias[vertice]
    caminho_texto = reconstruir_caminho(antecessores, origem, vertice)
    print(f"Até {vertice}: Distância = {dist} | Caminho: {caminho_texto}")
