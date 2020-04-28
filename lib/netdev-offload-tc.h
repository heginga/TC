#ifndef NETDEV_TC_OFFLOADS_H
#define NETDEV_TC_OFFLOADS_H 1

#include <stddef.h>
#include "netdev-provider.h"

int netdev_tc_flow_flush(struct netdev *);
int netdev_tc_flow_dump_create(struct netdev *, struct netdev_flow_dump **);
int netdev_tc_flow_dump_destroy(struct netdev_flow_dump *);
static bool netdev_tc_flow_dump_next(struct netdev_flow_dump *, struct match *,
                                     struct nlattr **actions,
                                     struct dpif_flow_stats *,
                                     ovs_u128 *ufid,
                                     struct ofpbuf *rbuffer,
                                     struct ofpbuf *wbuffer);
static int netdev_tc_flow_put(struct netdev *, struct match *,
                       struct nlattr *actions, size_t actions_len,
                       const ovs_u128 *, struct offload_info *,
                       struct dpif_flow_stats *);
static int netdev_tc_flow_get(struct netdev *netdev,
                   struct match *match,
                   struct nlattr **actions,
                   const ovs_u128 *ufid,
                   struct dpif_flow_stats *stats,
                   struct dpif_flow_attrs *attrs,
                   struct ofpbuf *buf);
static int netdev_tc_flow_del(struct netdev *, const ovs_u128 *,
                       struct dpif_flow_stats *);
static int netdev_tc_init_flow_api(struct netdev *);

#endif /* netdev-offload-tc.h */
