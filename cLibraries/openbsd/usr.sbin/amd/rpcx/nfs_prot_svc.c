/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "nfs_prot.h"
#include "am.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>/* getenv, exit */
#include <rpc/pmap_clnt.h> /* for pmap_unset */
#include <string.h> /* strcmp */ 
#include <netdb.h>
#include <signal.h>
#include <sys/ttycom.h>/* TIOCNOTTY */
#ifdef __cplusplus
#include <sysent.h> /* getdtablesize, open */
#endif /* __cplusplus */
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <syslog.h>
#include <errno.h>

#ifdef __STDC__
#define SIG_PF void(*)(int)
#endif

#ifdef DEBUG
#define RPC_SVC_FG
#endif

#define _RPCSVC_CLOSEDOWN 120
extern int _rpcpmstart;		/* Started by a port monitor ? */
extern int _rpcfdtype;		/* Whether Stream or Datagram ? */


void	nfs_program_2(struct svc_req *rqstp, SVCXPRT *transp);

void
nfs_program_2(struct svc_req *rqstp, SVCXPRT *transp)
{
	union {
		nfs_fh nfsproc_getattr_2_arg;
		sattrargs nfsproc_setattr_2_arg;
		diropargs nfsproc_lookup_2_arg;
		nfs_fh nfsproc_readlink_2_arg;
		readargs nfsproc_read_2_arg;
		writeargs nfsproc_write_2_arg;
		createargs nfsproc_create_2_arg;
		diropargs nfsproc_remove_2_arg;
		renameargs nfsproc_rename_2_arg;
		linkargs nfsproc_link_2_arg;
		symlinkargs nfsproc_symlink_2_arg;
		createargs nfsproc_mkdir_2_arg;
		diropargs nfsproc_rmdir_2_arg;
		readdirargs nfsproc_readdir_2_arg;
		nfs_fh nfsproc_statfs_2_arg;
	} argument;
	char *result;
	xdrproc_t xdr_argument, xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NFSPROC_NULL:
		xdr_argument = (xdrproc_t) xdr_void;
		xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_null_2_svc;
		break;

	case NFSPROC_GETATTR:
		xdr_argument = (xdrproc_t) xdr_nfs_fh;
		xdr_result = (xdrproc_t) xdr_attrstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_getattr_2_svc;
		break;

	case NFSPROC_SETATTR:
		xdr_argument = (xdrproc_t) xdr_sattrargs;
		xdr_result = (xdrproc_t) xdr_attrstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_setattr_2_svc;
		break;

	case NFSPROC_ROOT:
		xdr_argument = (xdrproc_t) xdr_void;
		xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_root_2_svc;
		break;

	case NFSPROC_LOOKUP:
		xdr_argument = (xdrproc_t) xdr_diropargs;
		xdr_result = (xdrproc_t) xdr_diropres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_lookup_2_svc;
		break;

	case NFSPROC_READLINK:
		xdr_argument = (xdrproc_t) xdr_nfs_fh;
		xdr_result = (xdrproc_t) xdr_readlinkres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_readlink_2_svc;
		break;

	case NFSPROC_READ:
		xdr_argument = (xdrproc_t) xdr_readargs;
		xdr_result = (xdrproc_t) xdr_readres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_read_2_svc;
		break;

	case NFSPROC_WRITECACHE:
		xdr_argument = (xdrproc_t) xdr_void;
		xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_writecache_2_svc;
		break;

	case NFSPROC_WRITE:
		xdr_argument = (xdrproc_t) xdr_writeargs;
		xdr_result = (xdrproc_t) xdr_attrstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_write_2_svc;
		break;

	case NFSPROC_CREATE:
		xdr_argument = (xdrproc_t) xdr_createargs;
		xdr_result = (xdrproc_t) xdr_diropres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_create_2_svc;
		break;

	case NFSPROC_REMOVE:
		xdr_argument = (xdrproc_t) xdr_diropargs;
		xdr_result = (xdrproc_t) xdr_nfsstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_remove_2_svc;
		break;

	case NFSPROC_RENAME:
		xdr_argument = (xdrproc_t) xdr_renameargs;
		xdr_result = (xdrproc_t) xdr_nfsstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_rename_2_svc;
		break;

	case NFSPROC_LINK:
		xdr_argument = (xdrproc_t) xdr_linkargs;
		xdr_result = (xdrproc_t) xdr_nfsstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_link_2_svc;
		break;

	case NFSPROC_SYMLINK:
		xdr_argument = (xdrproc_t) xdr_symlinkargs;
		xdr_result = (xdrproc_t) xdr_nfsstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_symlink_2_svc;
		break;

	case NFSPROC_MKDIR:
		xdr_argument = (xdrproc_t) xdr_createargs;
		xdr_result = (xdrproc_t) xdr_diropres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_mkdir_2_svc;
		break;

	case NFSPROC_RMDIR:
		xdr_argument = (xdrproc_t) xdr_diropargs;
		xdr_result = (xdrproc_t) xdr_nfsstat;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_rmdir_2_svc;
		break;

	case NFSPROC_READDIR:
		xdr_argument = (xdrproc_t) xdr_readdirargs;
		xdr_result = (xdrproc_t) xdr_readdirres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_readdir_2_svc;
		break;

	case NFSPROC_STATFS:
		xdr_argument = (xdrproc_t) xdr_nfs_fh;
		xdr_result = (xdrproc_t) xdr_statfsres;
		local = (char *(*)(char *, struct svc_req *)) nfsproc_statfs_2_svc;
		break;

	default:
		svcerr_noproc(transp);
		return;
	}
	(void) memset((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs(transp, xdr_argument, (caddr_t) &argument)) {
		svcerr_decode(transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, xdr_result, result)) {
		svcerr_systemerr(transp);
	}
	if (!svc_freeargs(transp, xdr_argument, (caddr_t) &argument)) {
		plog(XLOG_FATAL, "unable to free rpc arguments in nfs_program");
		going_down(1);
	}
	return;
}