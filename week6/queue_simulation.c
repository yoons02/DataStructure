#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue_simulation.h"


void main()
{
	int duration;

	// 	srand(time(NULL));
	while (current_time < MAX_SIMUL_TIME) {
		printf("\n----- time %d ----- \n", current_time);

		// 새 job이 들어오면 큐에 삽입
		if (is_job_arrived()) {
			++new_job_id;
			duration = get_random_duration();
			insert_job_into_queue(new_job_id, current_time, duration);
		}
		else{
			// 프린터가 놀고 있으면 다음 job을 수행
		if (is_printer_idle()) {
			if (!is_queue_empty()) {
				process_next_job();
				queue_show();
				++current_time;
			}
		}

		// 아직 프린트 중 
		else {
			printf("아직 Jop <% d>을 프린트하고 있습니다 ...남은 시간 : % d \n", current_job_id, remaining_time);
			--remaining_time;
			queue_show();
			++current_time;
		}

		}
		// 현재 큐의 상태를 보여줌 
	}

	double average_wate_time = (double)total_wait_time /num_printed_jobs;

	printf("\n완료된 프린트 job = %d 개", num_printed_jobs);
	printf("\n평균 지연 시간 = %f 단위시간 ", average_wate_time);
	// 통계 자료 출력  - 완료된 프린트 job 수, 평균 지연 시간 (total_wait_time/num_printed_jobs)
}


// ID가 id, 요청시간이 arrival_time, 프린트 시간이 duration인 Job을 큐에 삽입
void insert_job_into_queue(int id, int arrival_time, int duration)
{
	Job p;
	p.id = id;
	p.arrival_time = arrival_time;
	p.duration = duration;

	addq(p);

	// id, arrival_time, duration 설정 후 job p를 큐에 삽입
	// addq() 사용  

	printf(" 새 jop <%d>이 들어 왔습니다. 프린트 시간은 = %d 입니다. \n", id, duration);
}

// 다음 job을 큐에서 꺼내 수행(현재 job id, remaining time 등 설정)
void process_next_job()
{
	Job p;

	p = deleteq();
	current_job_id = p.id;
	remaining_time = p.duration-1;
	total_wait_time += current_time - p.arrival_time;

	// deleteq() 사용 
	// 다음 job을 큐에서 꺼내와 
	//	current_job_id, remaining_time (duration – 1), 
	//	total_wait_time (total_wait_time + (current_time – arrival_time) 설정

	++num_printed_jobs;
	printf(" 프린트를 시작합니다 - jop <%d>... \n", current_job_id);
}


// 새로운 job이 도착했는지를 랜덤하게 결정. True일 확률은 ARRIVAL_PROB
boolean is_job_arrived()
{
	if (random() < JOB_ARRIVAL_PROB)
		return true;
	else
		return false;
}

// 프린터가 놀고 있는지를 결정. 현재 job의 remaining time <= 0이면 true
boolean is_printer_idle()
{
	if (remaining_time <= 0)
		return true;
	else
		return false;
}

// 0.0 ~ 1.0 사이의 랜덤 값을 반환 
double random()
{
	return rand() / (double)RAND_MAX;
}

// 1 ~ MAX_PRINTING_TIME+1 사이의 랜덤 값을 반환
int get_random_duration()
{
	return (int)(MAX_PRINTING_TIME * random()) + 1;
}


void addq(Job e) {
	queue_pointer add = (queue_pointer)malloc(sizeof(queue));
	add->item = e;
	add->link = NULL;

	if (is_queue_empty()) {
		front = rear = add;
	}
	else {
		rear->link = add;
		rear = add;
	}
}

Job deleteq() {
	Job c;
	queue_pointer tmp;

	c = front->item;
	tmp = front;
	front = front->link;
	free(tmp);
	return c;
}

void queue_show() {
	queue_pointer tmp = front;

	printf("\n현재 프린터 큐 :[");
	while (tmp != NULL) {
		printf("%3d(%d)", tmp->item.id,tmp->item.duration);
		tmp = tmp->link;
	}
	printf(" ]\n");

}

boolean is_queue_empty()
{
	if (front == NULL)
		return true;
	else
		return false;
}        
