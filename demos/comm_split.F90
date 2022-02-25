program comm_split
	use mpi_f08
	implicit none

	integer :: ntasks, rank, ierr, color
	type(mpi_comm) :: subcomm
	integer :: color, subrank, subtasks

	call mpi_init(ierr)
	call mpi_comm_size(MPI_COMM_WORLD, ntasks, ierr)
	call mpi_comm_rank(MPI_COMM_WORLD, rank, ierr)

	if (mod(rank,2) == 0) then
		color = 1
	else
		color = 2
	end if

	! call mpi_comm_split(MPI_COMM_WORLD, color, rank, subcomm)
	! call mpi_comm_size(subcomm, subtasks)
	! call mpi_comm_rank(subcomm, subrank)

	! write(*, '(A,I3, A, I3, A, I3)') 'I am', rank, ' in MPI_COMM_WORLD but', & subrank, ' in subcomm', color
	write(*, '(A, I3, A)') 'I am ', rank, ' in MPI_COMM_WORLD'

	! call mpi_comm_free(subcomm)
	call mpi_finalize(ierr)

end program comm_split
